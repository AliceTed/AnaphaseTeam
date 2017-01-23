/**
 * @file Sound.h
 * @brief �T�E���h�N���X
 * @author Ruri
 * @date 2016.11.28
 */

#pragma once


#include <string>
#include "../../header/data/id/BGM_ID.h"
#include "../../header/data/id/SE_ID.h"
using namespace std;

class Sound
{
public:
	Sound();
	~Sound();
	/*
	�ǂݍ��ݏ������݂͐�p�N���X�Ɉڍs����
	*/
	void playBGM(BGM_ID _id);
	void stopBGM(BGM_ID _id);
	void pauseBGM(BGM_ID _id);
	void restartBGM(BGM_ID _id);
	void bgmVolume(BGM_ID _id, float _volume);
	void bgmFade(BGM_ID _id, float _deltaTime);

	void playSE(SE_ID _id);
	void stopSE(SE_ID _id);

private:
	float m_volume;
	float m_max;

};
