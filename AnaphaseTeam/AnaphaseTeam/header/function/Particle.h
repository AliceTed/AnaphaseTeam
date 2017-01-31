/**
@file
@brief	パーティクル
@author Yuuho Aritomi
@date	2017/01/31
*/
#pragma once

#include <gslib.h>
#include "data/id/TEXTURE_ID.h"

class IRenderer;

/**
@class
@brief パーティクル
*/
class Particle
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	Particle(const GSvector3 _pos, TEXTURE_ID _id = TEXTURE_ID::PARTICLE);
	/**
	@fn
	@brief デストラクタ
	*/
	~Particle();
	/**
	@fn
	@brief 初期化
	*/
	void initialize();
	/**
	@fn
	@brief 更新
	@param _deltaTime
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief 描画
	@param _renderer
	*/
	void draw(IRenderer* _renderer);
private:
	TEXTURE_ID m_texID;
	GSvector3 m_pos;
};