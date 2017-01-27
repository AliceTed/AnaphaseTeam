#include "camera/Perspective.h"
#include "renderer/IRenderer.h"
#include "camera/Zoom.h"

//コンストラクタ
Perspective::Perspective() :
	mPerspective(0.f, 0.f, 0.f, 0.f),
	mMatProjection(),
	mZoom(std::make_unique<Zoom>())
{
	gsMatrix4Identity(&mMatProjection);
}

//デストラクタ
Perspective::~Perspective()
{
}

//初期化
void Perspective::init(const GSvector4 & _perspective)
{
	mPerspective = _perspective;
	mZoom->init(mPerspective.x);
}

//更新
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

//更新（レンダラー）
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

//パースペクティブ値を返す
GSvector4 Perspective::perspective()
{
	return mPerspective;
}

//ズーム機能を渡す
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
