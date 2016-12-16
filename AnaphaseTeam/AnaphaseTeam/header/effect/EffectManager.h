/**
* @file		EffectManager.h
* @brief	「　エフェクトマネージャー　」
* @author	AY_Saito
* @date		2016/12/05 Ver1.00
* */
#pragma once

#include <GSgame.h>
#include <Effekseer.h>
#include <EffekseerRendererGL.h>
#include <unordered_map>
#include "../../header/data/id/EFFECT_ID.h"

class EffectManager
{
public:
	static EffectManager & getInstance();

	// デストラクタ
	~EffectManager();
	// エフェクト読み込み
	void loadEffect(EFFECT_ID _id, const wchar_t& _name);
	// 初期化
	void initialize();
	// 更新
	void update();
	// 描画
	void draw();
	// 解放
	void end();

	// エフェクト再生
	void effectPlay(EFFECT_ID _id, GSvector3 _position);
	// エフェクト解放
	void effectDelete();
private:
	// コンストラクタ
	EffectManager();
	// コピー禁止
	EffectManager(const EffectManager & other);
	EffectManager & operator  = (const EffectManager & other);

	// 各種行列の設定
	void effectMatrixSetting();
	// GSmatrix4からEffekseer::Matrix44へ変換
	Effekseer::Matrix44 mat4Conversion(const GSmatrix4 &mat4);

private:
	// エフェクト描画用インスタンス
	::EffekseerRenderer::Renderer* renderer;
	// エフェクト管理用インスタンス
	::Effekseer::Manager* manager;

	// エフェクト格納コンテナ型
	using EffectContaier = std::unordered_map<EFFECT_ID, Effekseer::Effect*>;
	// エフェクト格納コンテナ
	EffectContaier m_effectContainer;
	// ハンドル格納用コンテナ型
	using HandleContaier = std::unordered_map<EFFECT_ID, Effekseer::Handle>;
	// ハンドル格納コンテナ
	HandleContaier m_handleContainer;

	//Effekseer::Effect* effect;
	//Effekseer::Handle handle;

};