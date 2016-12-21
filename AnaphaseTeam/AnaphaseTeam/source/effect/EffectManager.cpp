#include "../../header/effect/EffectManager.h"
#include "../../header/data/id/EFFECT_ID.h"

#ifdef _DEBUG
#pragma comment(lib, "VS2015/Debug/Effekseer.lib" )
#pragma comment(lib, "VS2015/Debug/EffekseerRendererGL.lib" )
#else
#pragma comment(lib, "VS2015/Release/Effekseer.lib" )
#pragma comment(lib, "VS2015/Release/EffekseerRendererGL.lib" )
#endif

const int MAX_SPRITE = 100;		// 最大スプライト描画数
const int MAX_MANAGER = 100;	// 最大マネージャーインスタンス数

EffectManager::EffectManager()
	:m_effectContainer()
{
	initialize();
}

EffectManager & EffectManager::getInstance()
{
	static EffectManager self;
	return self;
}

EffectManager::~EffectManager()
{
	end();
}
/* 読み込み処理 */
void EffectManager::loadEffect(EFFECT_ID _id, const wchar_t* _name)
{
	m_effectContainer.insert(std::make_pair(_id, Effekseer::Effect::Create(manager, (const EFK_CHAR*)_name/*L"./Effect/Attack.efk"*/, 3.0f)));
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
	// 各種行列の設定
	effectMatrixSetting();
	// 全てのエフェクトの更新
	manager->Update();

	// 再生中のエフェクトの移動
	//	manager->AddLocation(handle, ::Effekseer::Vector3D(0.0f, 0.0f, 0.0f));
}
/* 描画処理 */
void EffectManager::draw()
{

	renderer->BeginRendering();
	manager->Draw();
	renderer->EndRendering();
}
/* 解放処理 */
void EffectManager::end()
{
	// エフェクト管理用インスタンスを破棄
	manager->Destroy();
	// 描画用インスタンスを破棄
	renderer->Destory();
}

/* エフェクト再生 */
void EffectManager::effectPlay(EFFECT_ID _id, GSvector3 _pos)
{
	m_handleContainer[_id] = manager->Play(m_effectContainer[_id], _pos.x, _pos.y, _pos.z);
}
/* エフェクト解放 */
void EffectManager::effectDelete()
{
	for (auto & i : m_effectContainer)
	{
		// エフェクト解放
		// 再生中の場合は、再生が終了した後、自動的に解放されます。
		ES_SAFE_RELEASE(i.second);
	}
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
Effekseer::Matrix44 EffectManager::mat4Conversion(const GSmatrix4 &mat4)
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