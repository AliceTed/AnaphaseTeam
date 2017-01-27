/**
* @file		EffectManager.h
* @brief	「　エフェクトマネージャー　」
* @author	AY_Saito
* @date		2016/12/05 Ver1.00
* @date		2016/12/22 Ver1.01 メモリリーク対応
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
	void loadEffect(EFFECT_ID _id, const std::string* _name);
	// 更新
	void update();
	// 描画
	void draw();
	// エフェクト再生
	void effectPlay(EFFECT_ID _id, GSvector3 _position);

	int gethandlsize() 
	{
		return m_handleContainer.size();
	}

	void setpos(EFFECT_ID id, GSvector3 p)
	{
		if (m_handleContainer.count(id) == 0)return;
		Effekseer::Vector3D v;
		v.X = p.x;
		v.Y = p.y;
		v.Z = p.z;

		manager->SetLocation(m_handleContainer[id], v);
	}
private:
	template< typename ContainerT, typename PredicateT >
	void erase_if(ContainerT& items, const PredicateT& predicate) 
	{
		for (auto it = items.begin(); it != items.end(); ) 
		{
			if (predicate(*it)) it = items.erase(it);
			else ++it;
		}
	};

	// コンストラクタ
	EffectManager();
	// コピー禁止
	EffectManager(const EffectManager & other);
	EffectManager & operator  = (const EffectManager & other);

	// 初期化
	void initialize();
	// 解放
	void end();

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

};