#include "camera/Perspective.h"
#include "renderer/IRenderer.h"
#include "camera/Zoom.h"

//�R���X�g���N�^
Perspective::Perspective() :
	mPerspective(0.f, 0.f, 0.f, 0.f),
	mMatProjection(),
	mZoom(std::make_unique<Zoom>())
{
	gsMatrix4Identity(&mMatProjection);
}

//�f�X�g���N�^
Perspective::~Perspective()
{
}

//������
void Perspective::init(const GSvector4 & _perspective)
{
	mPerspective = _perspective;
	mZoom->init(mPerspective.x);
}

//�X�V
void Perspective::update()
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(
		mPerspective.x,
		mPerspective.y,
		mPerspective.z,
		mPerspective.w
	);

	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&mMatProjection);

	mZoom->update(&mPerspective.x);
}

//�X�V�i�����_���[�j
void Perspective::update(IRenderer * _renderer)
{
	_renderer->perspective(
		mPerspective.x,
		mPerspective.y,
		mPerspective.z,
		mPerspective.w
	);

	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&mMatProjection);

	mZoom->update(&mPerspective.x);
}

//�p�[�X�y�N�e�B�u�l��Ԃ�
GSvector4 Perspective::perspective()
{
	return mPerspective;
}

//�Y�[���@�\��n��
Zoom * Perspective::zoom()
{
	return mZoom.get();
}

float Perspective::near()
{
	return mPerspective.z;
}

GSmatrix4 Perspective::matProjective()
{
	return mMatProjection;
}
