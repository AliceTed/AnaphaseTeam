#include "../../header/effect/EffectManager.h"
#include "../../header/data/id/EFFECT_ID.h"

#ifdef _DEBUG
#pragma comment(lib, "VS2015/Debug/Effekseer.lib" )
#pragma comment(lib, "VS2015/Debug/EffekseerRendererGL.lib" )
#else
#pragma comment(lib, "VS2015/Release/Effekseer.lib" )
#pragma comment(lib, "VS2015/Release/EffekseerRendererGL.lib" )
#endif

const int MAX_SPRITE = 100;		// �ő�X�v���C�g�`�搔
const int MAX_MANAGER = 100;	// �ő�}�l�[�W���[�C���X�^���X��

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
/* �ǂݍ��ݏ��� */
void EffectManager::loadEffect(EFFECT_ID _id, const wchar_t* _name)
{
	m_effectContainer.insert(std::make_pair(_id, Effekseer::Effect::Create(manager, (const EFK_CHAR*)_name/*L"./Effect/Attack.efk"*/, 3.0f)));
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
	// �e��s��̐ݒ�
	effectMatrixSetting();
	// �S�ẴG�t�F�N�g�̍X�V
	manager->Update();

	// �Đ����̃G�t�F�N�g�̈ړ�
	//	manager->AddLocation(handle, ::Effekseer::Vector3D(0.0f, 0.0f, 0.0f));
}
/* �`�揈�� */
void EffectManager::draw()
{

	renderer->BeginRendering();
	manager->Draw();
	renderer->EndRendering();
}
/* ������� */
void EffectManager::end()
{
	// �G�t�F�N�g�Ǘ��p�C���X�^���X��j��
	manager->Destroy();
	// �`��p�C���X�^���X��j��
	renderer->Destory();
}

/* �G�t�F�N�g�Đ� */
void EffectManager::effectPlay(EFFECT_ID _id, GSvector3 _pos)
{
	m_handleContainer[_id] = manager->Play(m_effectContainer[_id], _pos.x, _pos.y, _pos.z);
}
/* �G�t�F�N�g��� */
void EffectManager::effectDelete()
{
	for (auto & i : m_effectContainer)
	{
		// �G�t�F�N�g���
		// �Đ����̏ꍇ�́A�Đ����I��������A�����I�ɉ������܂��B
		ES_SAFE_RELEASE(i.second);
	}
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