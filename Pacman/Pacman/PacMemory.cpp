
#include "pacMemory.h"
#include "pacUtility.h"
#include <cstdlib>


std::string cutOffFirstArg(char * path, char sign)
{
	int i, ip1 , length;
	char returnValue[BUFFER_SIZE] = "\0";
	char buffer[BUFFER_SIZE] = "\0";

	if ((length = strlen(path)) >= BUFFER_SIZE)
	{
		POST_DEBUG_MESSAGE(-1, "Invalid path (too long)");
		return std::string();
	}

	// Count the amount of characters of the first arg
	for (i = 0; path[i] != sign && i < BUFFER_SIZE && i < length; i++);
	if (i == BUFFER_SIZE)
	{
		POST_DEBUG_MESSAGE(-1, "No Argument found.");
		return std::string();
	}

	// Get first arg
	memcpy(returnValue, path, i);
	memcpy(buffer, path, length);
	ip1 = i + 1;
	
	// Cut arg off
	for (i = ip1; i < length; i++)
		path[i - ip1] = buffer[i];
	path[i - ip1] = '\0';

	return std::string(returnValue);
}

void isolateData(char * data)
{
	int f, b, i, length;
	char * buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	memset(buffer, 0, BUFFER_SIZE);

	if ((length = strlen(data)) >= BUFFER_SIZE)
	{
		POST_DEBUG_MESSAGE(-1, "data too long for buffer");
		return;
	}

	for (f = 0; (data[f] == ' ' || data[f] == '\n') && f < length; f++);
	for (b = length; data[b] == ' ' || data[b] == '\n'; b--);

	for (i = f; i < b; i++)
		data[i - f] = data[i];
	data[i - f] = '\0';

	delete[] buffer;
}

void shortenData(char * data)
{
}

// Make sure to free the memory!
const char * load(const char * filePath, const char * dataPath)
{
	tinyxml2::XMLDocument		file;
	tinyxml2::XMLElement*		elementBuffer;
	std::string					strBuffer;			// Std::string for dynamic size and passing by value
	const char*					dataFromPath;
	char*						returnValue;
	char*						newDataPath;
	int							i;

	returnValue = (char *)malloc(sizeof(char) * BUFFER_SIZE);	// Heap-allocation for being able to return an array
	newDataPath = (char *)malloc(sizeof(char) * BUFFER_SIZE);	// Heap-allocation for changeable Lvalue
	memset(returnValue, 0, BUFFER_SIZE);
	memset(newDataPath, 0, BUFFER_SIZE);
	memcpy(newDataPath, dataPath, strlen(dataPath));

	if (file.LoadFile(filePath)) 
		POST_DEBUG_MESSAGE(pac::CUSTOM, "XMLError | Unable to load file");

	if (!(strBuffer = cutOffFirstArg(newDataPath, '.')).c_str())
		POST_DEBUG_MESSAGE(-1, "Invalid function parameter (dataPath)");

	// Follow path to data
	elementBuffer = file.FirstChildElement(strBuffer.c_str());
	for (i = 0; newDataPath[0] != '\0'; i++)
	{
		strBuffer = cutOffFirstArg(newDataPath, '.');
		elementBuffer = elementBuffer->FirstChildElement(strBuffer.c_str());
		if (i >= BUFFER_SIZE)
		{
			POST_DEBUG_MESSAGE(-1, "Invalid path / not existing path");
		}
	}

	// Store data
	dataFromPath = elementBuffer->GetText();
	memcpy(returnValue, dataFromPath, strlen(dataFromPath));
	if (!returnValue) POST_DEBUG_MESSAGE(-1, "No Value to store.");

	isolateData(returnValue);

	delete[] newDataPath;
	return returnValue;
}

const char * save(const char * file, const char * dataPath, const char * data)
{
	return nullptr;
}

pac::Result printFile(const char * filePath)
{
	FILE * f;
	pac::Result result;
	short xPos, yPos;
	char buffer = '\0';

	if (result = GetCursorPosition(xPos, yPos))
	{
		POST_DEBUG_MESSAGE(-1, "Filed to get cursor position");
		return result;
	}

	if (fopen_s(&f, filePath, "r"))
	{
		POST_DEBUG_MESSAGE(-1, "Failed to open file");
		return pac::Result::FAILURE;
	}

	buffer = fgetc(f);
	while (buffer != EOF)
	{
		while (buffer != EOF && buffer != '\n')
		{
			putchar(buffer);
			buffer = fgetc(f);
		}
		yPos++;
		if (SetCursorPosition(xPos, yPos))
		{
			POST_DEBUG_MESSAGE(-1, "Failed to set cursor position");
			return pac::Result::FAILURE;
		}
		buffer = fgetc(f);
	}

	return pac::Result::SUCCESS;
}

pac::Result printData(const char * filePath, const char * dataPath)
{
	const char * buffer = load(filePath, dataPath);
	printf(buffer);
	delete[] buffer;

	return pac::Result();
}
