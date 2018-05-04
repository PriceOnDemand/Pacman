#pragma once

#include "ExtSrc\TinyXML\tinyxml2.h"
#include "pacError.h"
#include <string>

#define BUFFER_SIZE 255


// Utility
std::string cutOffFirstArg(char * path, char sign);
void isolateData(char * data);
void shortenData(char * data);

// Basic load/save
const char* load(const char * file, const char * dataPath);		// Make sure to free the buffer!
const char* save(const char * file, const char * dataPath, const char * data);

// Direct output
pac::Result printFile(const char * filePath);
pac::Result printData(const char * filePath, const char * dataPath);