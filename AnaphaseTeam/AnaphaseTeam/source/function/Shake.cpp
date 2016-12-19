#include "../../header/function/Shake.h"
#include "../../header/spline/AnimationSpline.h"
#include "../../header/math/AMath.h"
#include <random>

Shake::Shake(const GSvector3& _scale, float _time) :
	points(_time),
	animSpline(std::make_unique<AnimationSpline>())
{
	std::random_device rnd;		//�����_���{��
	std::mt19937 mt(rnd());		//�����_���Ɋ֘A��������
	int i;						//�v�f���̍Ōオ�~�����̂�

	//�^�C�}�[�̐������X�v���C�g��p��
	for (i = 0; i < _time - 1; i++)
	{
		//(-_scale ~ _scale)�͈̔͂łR�����x�N�g���̐����������_������
		std::uniform_real_distribution<> randX(-_scale.x, _scale.x);
		std::uniform_real_distribution<> randY(-_scale.y, _scale.y);
		std::uniform_real_distribution<> randZ(-_scale.z, _scale.z);

		//�����_���������ꂽ�R�����x�N�g�����i�[
		points[i] = GSvector3(randX(mt), randY(mt), randZ(mt));
	}
	//�Ō�͕K���O�ɂȂ�
	points[i] = GSvector3(0.0f, 0.0f, 0.0f);

	//�X�v���C���Ȑ��̏��̏�����
	animSpline->init(points);
}

Shake::~Shake()
{

}

GSvector3 Shake::run(float _speed, const GSvector3& _center)
{
	//�A�j���[�V�������s
	return animSpline->run(_speed, _center);
}

void Shake::resetTime(void)
{
	//���Ԃ̃��Z�b�g
	animSpline->resetTime();
}
