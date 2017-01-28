#include "camera/Zoom.h"
#include "math/Calculate.h"

//デフォルトコンストラクタ
Zoom::Zoom() :
	mZoomValue(0.0f)
{
}

//デストラクタ
Zoom::~Zoom()
{
}

//初期化
void Zoom::init(const float _zoom)
{
	mZoomValue = _zoom;
}

//更新
void Zoom::update(float * _zoom)
{
	*_zoom = mZoomValue;
}

//ズームイン
void Zoom::zoomIN(const float _speed)
{
	mZoomValue -= _speed;
}

//ズームアウト
void Zoom::zoomOut(const float _speed)
{
	mZoomValue += _speed;
}

//ズームできる範囲を決定する
void Zoom::clamp(float _min, float _max)
{
	mZoomValue = Math::Calculate::clamp(mZoomValue, _min, _max);
}
