#include "function\Particle.h"
#include "renderer\IRenderer.h"
#include "renderer\define\SpriteRenderDesc.h"
#include "math\Calculate.h"

//コンストラクタ
Particle::Particle(const GSvector3 _pos, TEXTURE_ID _id) :
	m_texID(_id),
	m_pos(_pos),
	m_pos_offset(0.f, 0.f, 0.f),
	m_time(0.f),
	m_isDead(false)
{
}

//デストラクタ
Particle::~Particle()
{
}

//初期化
void Particle::initialize()
{
}

//更新
void Particle::update(float _deltaTime)
{
	//左右に揺れる処理
	float scale = 10.f;
	m_time += _deltaTime;
	m_pos_offset.x = Math::Calculate::cos(m_time) * scale;

	//上に落ちる処理
	float speed = 1.f;
	GSvector3 gravity = GSvector3(0.f, -1.f, 0.f);
	m_pos += gravity * speed;

	//上まで行ったら死亡
	if (m_pos.y < -50.f) {
		m_isDead = true;
	}
}

//描画
void Particle::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_texID);
	desc.matrix.setTranslation(m_pos + m_pos_offset);
	_renderer->render(desc);
}

//死んだか？
bool Particle::isDead()
{
	return m_isDead;
}
