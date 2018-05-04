#include "pacSound.h"

Sound::Sound(const char *filePath)
{
	file = filePath;
}

pac::Result Sound::play() const
{
	return pac::Result();
}

pac::Result Sound::pause() const
{
	return pac::Result();
}

pac::Result Sound::stop() const
{
	return pac::Result();
}
