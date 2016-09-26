#include "../../header/camera/Perspective.h"

Perspective::Perspective(void) :
	fov(0.0f),
	aspect(0.0f),
	near(0.0f),
	far(0.0f)
{
}

Perspective::Perspective(
	const float _fov, 
	const float _aspect,
	const float _near, 
	const float _far) :
	fov(_fov),
	aspect(_aspect),
	near(_near),
	far(_far)
{
}