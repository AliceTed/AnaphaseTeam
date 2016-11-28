#include "../../header/sound/Sound.h"
#include <GSmath.h>

Sound::Sound() :
	m_volume(0),
	m_max(1)
{
}

Sound::~Sound()
{
}

void Sound::loadBGM(BGM_ID _id, const string& _name, const string& _path, const string& _extension)
{
	string fullpath = _path + _name + _extension;
	gsLoadMusic(static_cast<GSuint>(_id), fullpath.c_str(), GS_TRUE);
}

void Sound::deleteBGM()
{
	for (int i = 0; i < static_cast<int>(BGM_ID::SIZE); i++)
	{
		gsDeleteMusic(i);
	}
}

void Sound::playBGM(BGM_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsPlayMusic();
}

void Sound::stopBGM(BGM_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsStopMusic();
}

void Sound::pauseBGM(BGM_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsPauseMusic();
}

void Sound::restartBGM(BGM_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsRestartMusic();
}

void Sound::bgmVolume(BGM_ID _id, float _volume)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsSetMusicVolume(_volume);
}

void Sound::bgmFadeIn(BGM_ID _id, float _deltaTime)
{
	m_volume = LERP(_deltaTime, m_volume, m_max);
	gsBindMusic(static_cast<GSuint>(_id));
	if (gsGetMusicTime() <= 10.0f)
	{
		m_max = 1.0f;
		gsSetMusicVolume(m_volume);
	}
}

void Sound::bgmFadeOut(BGM_ID _id, float _deltaTime)
{
	m_volume = LERP(_deltaTime, m_volume, m_max);
	gsBindMusic(static_cast<GSuint>(_id));
	if (gsGetMusicTime() >= gsGetMusicEndTime() - 10.0f)
	{
		m_max = 0.0f;
		gsSetMusicVolume(m_volume);
	}
}

void Sound::loadSE(SE_ID _id, const string& _name, const string& _path, const string& _extension)
{
	string fullpath = _path + _name + _extension;
	gsLoadMusic(static_cast<GSuint>(_id), fullpath.c_str(), GS_FALSE);
}

void Sound::deleteSE()
{
	for (int i = static_cast<int>(BGM_ID::SIZE) - 1; i < static_cast<int>(SE_ID::SIZE); i++)
	{
		gsDeleteMusic(i);
	}
}

void Sound::playSE(SE_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsPlayMusic();
}