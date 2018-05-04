#pragma once

#include "pacError.h"


class Sound
{
private:
	const char *file;

public:
	Sound() = delete;
	Sound(const char *filePath);

	pac::Result play() const;
	pac::Result pause() const;
	pac::Result stop() const;
};