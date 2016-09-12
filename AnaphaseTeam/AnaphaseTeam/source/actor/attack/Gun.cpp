#include "../../../header/actor/attack/Gun.h"
#include "../../../header/actor/attack/IWeapon.h"

Gun::Gun(/*MODEL_ID _model_id*/)
	:m_gunValu(0.0f)
	//m_animator(_model_id)
{}
Gun::~Gun()
{}
void Gun::initialize()
{
	//m_animator.addAnimation(ANIMATION_ID::ATTACK, 1.4f);
}
void Gun::update()
{
	//animation();
}

void Gun::animation()
{
	//m_animator.changeAnimation(ANIMATION_ID::ATTACK);
}

