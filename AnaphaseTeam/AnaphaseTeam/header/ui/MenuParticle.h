/**
@file
@brief メニュー用パーティクル
@author Yuuho Aritomi
@date 2017/01/31
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "data/id/TEXTURE_ID.h"

class IRenderer;
class ParticleManager;
/**
@class
@brief メニュー用パーティクル
*/
class MenuParticle
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	MenuParticle();
	/**
	@fn
	@brief デストラクタ
	*/
	~MenuParticle();
	/**
	@fn
	@brief 初期化
	*/
	void initialize();
	/**
	@fn
	@brief 更新
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief 描画*/
	void draw(IRenderer* _renderer);
	/**
	@fn
	@brief 終了処理
	*/
	void finish();
private:
	std::unique_ptr<ParticleManager> m_particle;
};