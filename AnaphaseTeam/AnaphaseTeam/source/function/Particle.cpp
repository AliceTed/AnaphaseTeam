#include "function\Particle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"
#include "math\Calculate.h"

//�R���X�g���N�^
Particle::Particle(const GSvector3 _pos, TEXTURE_ID _id) :
	m_texID(_id),
	m_pos(_pos),
	m_pos_offset(0.f, 0.f, 0.f),
	m_time(0.f),
	m_isDead(false)
{
}

//�f�X�g���N�^
Particle::~Particle()
{
}

//������
void Particle::initialize()
{
}

//�X�V
void Particle::update(float _deltaTime)
{
	//���E�ɗh��鏈��
	float scale = 10.f;
	m_time += _deltaTime;
	m_pos_offset.x = Math::Calculate::cos(m_time) * scale;

	//��ɗ����鏈��
	float speed = 1.f;
	GSvector3 gravity = GSvector3(0.f, -1.f, 0.f);
	m_pos += gravity * speed;

	//��܂ōs�����玀�S
	if (m_pos.y < -50.f) {
		m_isDead = true;
	}
}

//�`��
void Particle::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_texID);
	desc.matrix.setTranslation(m_pos + m_pos_offset);
	_renderer->render(desc);
}

//���񂾂��H
bool Particle::isDead()
{
	return m_isDead;
}
