#pragma once

#include <cstdio>
#include <string>
#include <ctime>


namespace pac
{
	class Message
	{
	public:
		const char * msg = NULL;
		void CleanUp() { if (_CrtIsValidHeapPointer(msg))delete[] msg; }
	};

	enum Result
	{
		CUSTOM = -1,
		SUCCESS = 0,
		FAILURE = 1
	};

	Message TranslateResult(Result msg);
}


#define POST_DEBUG_MESSAGE(code, message)										\
{																				\
	time_t timestamp;															\
	tm *date = new tm;															\
	timestamp = time(0);														\
	localtime_s(date, &timestamp);												\
																				\
	FILE *f;																	\
	if (fopen_s(&f, "log.txt", "a+")) throw "log.txt not found";				\
																				\
	fprintf_s(f, "\n\n\n-------- " __DATE__ " --------------------------------------------------------------------------------------------------------------------\n\n" \
	"Time: " "%i:%i:%i" "\n"													\
	"File: " __FILE__ "\n"														\
	"Line: %i\n\n", date->tm_hour, date->tm_min, date->tm_sec, __LINE__);		\
	fprintf_s(f, "%i: '", code);												\
	fprintf_s(f, message);														\
	fprintf_s(f, "'\n\n-----------------------------------------------------------------------------------------------------------------------------------------"); \
																				\
	fclose(f);																	\
}

#define POST_DEFFAULT_MESSAGE(code)												\
{																				\
	pac::Message msg = pac::TranslateResult(code);								\
	POST_DEBUG_MESSAGE(code, msg.msg);											\
	msg.CleanUp();																\
}

#define PDM(code)																\
	if (code) POST_DEFFAULT_MESSAGE(code);

#define IFN(code)																\
	if (code) POST_DEBUG_MESSAGE(-1, "Undefined error");