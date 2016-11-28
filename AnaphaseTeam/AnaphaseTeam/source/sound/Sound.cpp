#include "../../header/sound/Sound.h"
#include <gslib.h>

Sound::Sound()
{
}

Sound::~Sound()
{
}

const void Sound::playBGM(BGM_ID _bgmID) const
{
	gsPlayBGM(static_cast<GSuint>(_bgmID));
}

const void Sound::stopBGM() const
{
	gsStopBGM();
}

const void Sound::playSE(SE_ID _seID) const
{
	gsPlaySE(static_cast<GSuint>(_seID));
}

const void Sound::stopSE(SE_ID _seID) const
{
	gsStopSE(static_cast<GSuint>(_seID));
}
