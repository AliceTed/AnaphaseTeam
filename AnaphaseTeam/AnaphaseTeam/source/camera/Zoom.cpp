#include "camera/Zoom.h"
#include "math/Calculate.h"

//�f�t�H���g�R���X�g���N�^
Zoom::Zoom() :
	mZoomValue(0.0f)
{
}

//�f�X�g���N�^
Zoom::~Zoom()
{
}

//������
void Zoom::init(const float _zoom)
{
	mZoomValue = _zoom;
}

//�X�V
void Zoom::update(float * _zoom)
{
	*_zoom = mZoomValue;
}

//�Y�[���C��
void Zoom::zoomIN(const float _speed)
{
	mZoomValue -= _speed;
}

//�Y�[���A�E�g
void Zoom::zoomOut(const float _speed)
{
	mZoomValue += _speed;
}

//�Y�[���ł���͈͂����肷��
void Zoom::clamp(float _min, float _max)
{
	mZoomValue = Math::Calculate::clamp(mZoomValue, _min, _max);
}
