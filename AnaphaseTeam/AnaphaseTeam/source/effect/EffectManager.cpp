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

const int MAX_SPRITE = 1500;		// �ő�X�v���C�g�`�搔
const int MAX_MANAGER = 1500;	// �ő�}�l�[�W���[�C���X�^���X��

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
	auto pair = std::make_pair(_id, Effekseer::Effect::Create(manager, (const EFK_CHAR*)_name, _scale));
	m_effectContainer.insert(pair);
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
void EffectManager::effectPlay(EFFECT_ID _id, const GSvector3& _pos)
{
	//�n���h���̓o�^�ƃG�t�F�N�g�̍Đ�
	auto pair = std::make_pair(_id, manager->Play(m_effectContainer[_id], _pos.x, _pos.y, _pos.z));
	m_handleContainer.insert(pair);
}

void EffectManager::clear()
{
	for (auto & i : m_effectContainer)
	{
		// �G�t�F�N�g���
		// �Đ����̏ꍇ�́A�Đ����I��������A�����I�ɉ������܂��B
		ES_SAFE_RELEASE(i.second);
	}
	m_effectContainer.clear();
	m_handleContainer.clear();
}

void EffectManager::stop(EFFECT_ID _id)
{
	//�w��G�t�F�N�g�̒�~�ƒ�~�����G�t�F�N�g�̃n���h�����폜
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
