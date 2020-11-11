#include "Sound.hpp"

void Moon::Sound::Play(const std::string& path) noexcept
{
	mciSendStringA((std::string("play ") + path).c_str(), NULL, 0, NULL);
}

void Moon::Sound::PlayFrom(const std::string& path, const uint32_t ms) noexcept
{
	mciSendStringA((std::string("open ") + path + std::string(" alias sound")).c_str(), 0, 0, 0);
	mciSendStringA("set sound time format ms", 0, 0, 0);
	mciSendStringA((std::string("seek sound to ") + std::to_string(ms)).c_str(), 0, 0, 0);
	mciSendStringA("play sound wait", 0, 0, 0);
	mciSendStringA("close sound", 0, 0, 0);
}
