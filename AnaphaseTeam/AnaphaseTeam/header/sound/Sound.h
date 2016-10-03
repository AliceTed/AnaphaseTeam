#pragma once
#include "../../header/data/SE_ID.h"
#include "../../header/data/BGM_ID.h"

class Sound
{
public:
	Sound();
	~Sound();
	const void playBGM(BGM_ID _bgmID) const;
	const void stopBGM() const;
	const void playSE(SE_ID _seID) const;
	const void stopSE(SE_ID _seID) const;
};