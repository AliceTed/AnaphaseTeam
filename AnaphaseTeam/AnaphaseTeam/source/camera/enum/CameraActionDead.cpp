#include "../../../header/camera/enum/CameraActionDead.h"
#include "../../../header/camera/Camera.h"

CameraActionDead::CameraActionDead(Camera* _camera) :
	m_camera(_camera)
{
	m_camera->zoom_clamp(20, 180);
}



CameraActionDead::~CameraActionDead()
{

}


//–¢Š®¬
void CameraActionDead::run(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();

	m_camera->follow_target(player + GSvector3(0, 1, 0), 0.5f);

	m_camera->zoom_in(1.0f);

	m_camera->update();

	/*m_camera->cameraWork_dolly(
		player, 
		30, 
		50, 
		5,
		0.5f,
		0.5f
	);*/

	return;
}