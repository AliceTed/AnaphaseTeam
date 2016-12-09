#include "../../header/camera/SLookAt.h"

SLookAt::SLookAt(GSvector3 _position, GSvector3 _target, GSvector3 _up) :
	position(_position),
	target(_target),
	target_offset(0.0f, 0.0f, 0.0f),
	up(0.0f, 1.0f, 0.0f),
	mat_view()
{
	//�V�F�[�_�[�p���f���r���[�ϊ��s��̏�����
	gsMatrix4Identity(&mat_view);
}

SLookAt::~SLookAt()
{
}
