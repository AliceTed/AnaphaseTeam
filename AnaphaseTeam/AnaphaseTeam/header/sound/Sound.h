/**
 * @file Sound.h
 * @brief サウンドクラス
 * @author Ruri
 * @date 2016.11.28
 */

#pragma once

#include <GSmusic.h>
#include <string>
#include "../../header/data/BGM_ID.h"
#include "../../header/data/SE_ID.h"
using namespace std;

class Sound
{
public:
	Sound();
	~Sound();
	void loadBGM(BGM_ID _id, const string& _name, const string& _path = "res/sound/", const string& _extension = ".wav");
	void deleteBGM();
	void playBGM(BGM_ID _id);
	void stopBGM(BGM_ID _id);
	void pauseBGM(BGM_ID _id);
	void restartBGM(BGM_ID _id);
	void bgmVolume(BGM_ID _id, float _volume);
	void bgmFade(BGM_ID _id, float _deltaTime);

	void loadSE(SE_ID _id, const string& _name, const string& _path = "res/sound/", const string& _extension = ".wav");
	void deleteSE();
	void playSE(SE_ID _id);
	void stopSE(SE_ID _id);

private:
	float m_volume;
	float m_max;

};
