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
	Particle(const GSvector2 _pos, TEXTURE_ID _id = TEXTURE_ID::PARTICLE);
	/**
	@fn
	@brief デストラクタ
	*/
	~Particle();
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
	/**
	@fn
	@brief 死んだか？
	@return 死んだか？
	*/
	bool isDead();
private:
	TEXTURE_ID m_texID;
	GSvector2 m_pos;
	GSvector2 m_pos_offset;
	float m_time;
	bool m_isDead;
	float m_speed;
};