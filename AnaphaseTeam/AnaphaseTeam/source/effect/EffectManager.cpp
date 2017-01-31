#include "../../header/effect/EffectManager.h"
#include "../../header/data/id/EFFECT_ID.h"
#include <Effekseer.h>
#include<algorithm>
#ifdef _DEBUG
#pragma comment(lib, "VS2015/Debug/Effekseer.lib" )
#pragma comment(lib, "VS2015/Debug/EffekseerRendererGL.lib" )
#else
#pragma comment(lib, "VS2015/Release/Effekseer.lib" )
#pragma comment(lib, "VS2015/Release/EffekseerRendererGL.lib" )
#endif

const int MAX_SPRITE = 1000;		// �ő�X�v���C�g�`�搔
const int MAX_MANAGER = 1000;	// �ő�}�l�[�W���[�C���X�^���X��

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
/* �f�X�g���N�^ */
EffectManager::~EffectManager()
{
	end();
}
/* �ǂݍ��ݏ��� */
void EffectManager::loadEffect(EFFECT_ID _id, const std::string* _name, float _scale)
{
	m_effectContainer.insert(std::make_pair(_id, Effekseer::Effect::Create(manager, (const EFK_CHAR*)_name,_scale)));
}
/* ���������� */
void EffectManager::initialize()
{
	// �`��Ǘ��C���X�^���X�̐���
	renderer = ::EffekseerRendererGL::Renderer::Create(MAX_SPRITE);
	// �G�t�F�N�g�Ǘ��p�C���X�^���X�̐���
	manager = ::Effekseer::Manager::Create(MAX_MANAGER);
	// �`����@�̎w��
	manager->SetSpriteRenderer(renderer->CreateSpriteRenderer());
	manager->SetRibbonRenderer(renderer->CreateRibbonRenderer());
	manager->SetRingRenderer(renderer->CreateRingRenderer());
	// �e�N�X�`���摜�̓ǂݍ��ݕ��@�̎w��
	manager->SetTextureLoader(renderer->CreateTextureLoader());
	// ���W�n�̎w��(RH�ŉE��n�ALH�ō���n)
	manager->SetCoordinateSystem(::Effekseer::CoordinateSystem::RH);
}
/* �X�V���� */
void EffectManager::update()
{
	// �S�ẴG�t�F�N�g�̍X�V
	manager->Update();
	// �Đ����̃G�t�F�N�g�̈ړ�
	//	manager->AddLocation(handle, ::Effekseer::Vector3D(0.0f, 0.0f, 0.0f));
	erase_if(m_handleContainer,[&](auto& p){return !manager->Exists(p.second);});
}
/* �`�揈�� */
void EffectManager::draw()
{
	// �e��s��̐ݒ�
	effectMatrixSetting();
	glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT);
	renderer->BeginRendering();
	manager->Draw();

	glPushAttrib(GL_ENABLE_BIT);

	renderer->EndRendering();
	glPopAttrib();

	glEnable(GL_DEPTH_TEST);
}
/* ������� */
void EffectManager::end()
{
	// �G�t�F�N�g�Ǘ��p�C���X�^���X��j��
	manager->Destroy();
	// �`��p�C���X�^���X��j��
	renderer->Destory();
	clear();
}

/* �G�t�F�N�g�Đ� */
void EffectManager::effectPlay(EFFECT_ID _id, GSvector3 _pos)
{
	m_handleContainer[_id] = manager->Play(m_effectContainer[_id], _pos.x, _pos.y, _pos.z);
}

void EffectManager::clear()
{
	for (auto & i : m_effectContainer)
	{
		// �G�t�F�N�g���
		// �Đ����̏ꍇ�́A�Đ����I��������A�����I�ɉ������܂��B
		manager->StopEffect(m_handleContainer[i.first]);
		ES_SAFE_RELEASE(i.second);
	}
	m_effectContainer.clear();
	//	manager->AddLocation(handle, ::Effekseer::Vector3D(0.0f, 0.0f, 0.0f));
	erase_if(m_handleContainer, [&](auto& p) {return !manager->Exists(p.second); });
}

void EffectManager::release(EFFECT_ID _id)
{
	ES_SAFE_RELEASE(m_effectContainer[_id]);
	m_handleContainer.erase(_id);
	m_effectContainer.erase(_id);
}

/* �e��s��̐ݒ� */
void EffectManager::effectMatrixSetting()
{
	GSmatrix4 projection;
	// �v���W�F�N�V�����s����擾
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&projection);
	// �v���W�F�N�V�����s��ݒ�
	Effekseer::Matrix44 matProjection = mat4Conversion(projection);
	renderer->SetProjectionMatrix(matProjection);
	GSmatrix4 view;
	// �J�����s����擾
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&view);
	// �J�����s��̐ݒ�
	Effekseer::Matrix44 matView = mat4Conversion(view);
	renderer->SetCameraMatrix(matView);
}
/* Matrix4�̕ϊ� */
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