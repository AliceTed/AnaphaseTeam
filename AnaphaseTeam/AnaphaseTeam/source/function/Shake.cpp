#include "function/Shake.h"
#include "spline/AnimationSpline.h"
#include "math/AMath.h"
#include <random>

//�f�t�H���g�R���X�g���N�^
Shake::Shake() :
	animSpline(std::make_unique<AnimationSpline>())
{
	init(GSvector3(0.f, 0.f, 0.f), 0, GSvector3(0.f, 0.f, 0.f));
}

//�f�X�g���N�^
Shake::~Shake()
{

}

//������
void Shake::init(const GSvector3 & _scale, const int _time, const GSvector3 & _center)
{
	std::vector<GSvector3> points(_time);
	std::random_device rnd;	
	std::mt19937 mt(rnd());	
	int i;

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
	animSpline->init(points, 1.f, _center);
}

//���s
GSvector3 Shake::run()
{
	return animSpline->run();
}

//�^�C�}�[���Z�b�g
void Shake::resetTime(void)
{
	animSpline->resetTime();
}
