#include "../../header/effect/EffectManager.h"
#include "../../header/data/id/EFFECT_ID.h"
#include <Effekseer.h>
#include<algorithm>
#include <cassert>
#ifdef _DEBUG
#pragma comment(lib, "VS2015/Debug/Effekseer.lib" )
#pragma comment(lib, "VS2015/Debug/EffekseerRendererGL.lib" )
#else
#pragma comment(lib, "VS2015/Release/Effekseer.lib" )
#pragma comment(lib, "VS2015/Release/EffekseerRendererGL.lib" )
#endif

const int MAX_SPRITE = 1500;		// 最大スプライト描画数
const int MAX_MANAGER = 1500;	// 最大マネージャーインスタンス数

EffectManager::EffectManager()
	:m_effectContainer(),
	m_handleContainer()
{
	initialize();
}

EffectManager & EffectManager::getInstance()
{
	static EffectManager self;
	return self;
}
/* デストラクタ */
EffectManager::~EffectManager()
{
	end();
}
/* 読み込み処理 */
void EffectManager::loadEffect(EFFECT_ID _id, const std::string* _name, float _scale)
{
	auto pair = std::make_pair(_id, Effekseer::Effect::Create(manager, (const EFK_CHAR*)_name, _scale));
	m_effectContainer.insert(pair);
}
/* 初期化処理 */
void EffectManager::initialize()
{
	// 描画管理インスタンスの生成
	renderer = ::EffekseerRendererGL::Renderer::Create(MAX_SPRITE);
	// エフェクト管理用インスタンスの生成
	manager = ::Effekseer::Manager::Create(MAX_MANAGER);
	// 描画方法の指定
	manager->SetSpriteRenderer(renderer->CreateSpriteRenderer());
	manager->SetRibbonRenderer(renderer->CreateRibbonRenderer());
	manager->SetRingRenderer(renderer->CreateRingRenderer());
	// テクスチャ画像の読み込み方法の指定
	manager->SetTextureLoader(renderer->CreateTextureLoader());
	// 座標系の指定(RHで右手系、LHで左手系)
	manager->SetCoordinateSystem(::Effekseer::CoordinateSystem::RH);
}
/* 更新処理 */
void EffectManager::update()
{
	// 全てのエフェクトの更新
	manager->Update();
}
/* 描画処理 */
void EffectManager::draw()
{
	// 各種行列の設定
	effectMatrixSetting();
	glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT);
	renderer->BeginRendering();
	manager->Draw();

	glPushAttrib(GL_ENABLE_BIT);

	renderer->EndRendering();
	glPopAttrib();

	glEnable(GL_DEPTH_TEST);
}
/* 解放処理 */
void EffectManager::end()
{
	// エフェクト管理用インスタンスを破棄
	manager->Destroy();
	// 描画用インスタンスを破棄
	renderer->Destory();
	clear();
}

/* エフェクト再生 */
void EffectManager::effectPlay(EFFECT_ID _id, const GSvector3& _pos)
{
	//ハンドルの登録とエフェクトの再生
	auto pair = std::make_pair(_id, manager->Play(m_effectContainer[_id], _pos.x, _pos.y, _pos.z));
	m_handleContainer.insert(pair);
}

void EffectManager::clear()
{
	for (auto & i : m_effectContainer)
	{
		// エフェクト解放
		// 再生中の場合は、再生が終了した後、自動的に解放されます。
		ES_SAFE_RELEASE(i.second);
	}
	m_effectContainer.clear();
	m_handleContainer.clear();
}

void EffectManager::stop(EFFECT_ID _id)
{
	//指定エフェクトの停止と停止したエフェクトのハンドルを削除
	if (m_handleContainer.count(_id)== 0)return;
	//assert(m_handleContainer.count(_id)!=0);
	manager->StopEffect(m_handleContainer[_id]);
	m_handleContainer.erase(_id);
}

void EffectManager::stopAll()
{
	manager->StopAllEffects();
	m_handleContainer.clear();
}

/* 各種行列の設定 */
void EffectManager::effectMatrixSetting()
{
	GSmatrix4 projection;
	// プロジェクション行列を取得
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&projection);
	// プロジェクション行列設定
	Effekseer::Matrix44 matProjection = mat4Conversion(projection);
	renderer->SetProjectionMatrix(matProjection);
	GSmatrix4 view;
	// カメラ行列を取得
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&view);
	// カメラ行列の設定
	Effekseer::Matrix44 matView = mat4Conversion(view);
	renderer->SetCameraMatrix(matView);
}
/* Matrix4の変換 */
Effekseer::Matrix44 EffectManager::mat4Conversion(const GSmatrix4 & mat4)
{
	Effekseer::Matrix44 mat;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			mat.Values[y][x] = mat4.m[y][x];
		}
	}
	return mat;
}

Effekseer::Vector3D EffectManager::vec3Convert(const GSvector3 & _v)
{
	return Effekseer::Vector3D(_v.x,_v.y,_v.z);
}
