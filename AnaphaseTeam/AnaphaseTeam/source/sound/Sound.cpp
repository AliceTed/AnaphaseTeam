#include "../../header/sound/Sound.h"
#include <GSmath.h>
#include <GSmusic.h>
Sound::Sound() :
	m_volume(0),
	m_max(1)
{
}

Sound::~Sound()
{
}
void Sound::playBGM(BGM_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	gsPlayMusic();
}

void Sound::stopBGM(BGM_ID _id)
{
	m_volume = 0;
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

void Sound::bgmFade(BGM_ID _id, float _deltaTime)
{
	m_volume = LERP(_deltaTime, m_volume, m_max);
	gsBindMusic(static_cast<GSuint>(_id));
	if (gsGetMusicTime() <= 10.0f)
	{
		m_max = 1.0f;
		gsSetMusicVolume(m_volume);
	}
	if (gsGetMusicTime() >= gsGetMusicEndTime() - 10.0f)
	{
		m_max = 0.0f;
		gsSetMusicVolume(m_volume);
	}
}
void Sound::playSE(SE_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	if (gsIsPlayMusic()) gsStopMusic();
	gsPlayMusic();
}

void Sound::stopSE(SE_ID _id)
{
	gsBindMusic(static_cast<GSuint>(_id));
	if (gsGetMusicTime() >= gsGetMusicEndTime())
	{
		gsStopMusic();
	}
}
