#include "../../header/camera/CameraActionData.h"
#include "../../header/camera/enum/CameraActionID.h"
#include "../../header/camera/CameraAction.h"

CameraActionData::CameraActionData() :
	m_cameraActions()
{
}


CameraActionData::~CameraActionData()
{
	m_cameraActions.clear();
}


void CameraActionData::load(
	const CameraActionID&	_id,
	CameraAction*			_date
)
{
	m_cameraActions.insert(cameraAction_map::value_type((int)_id, _date));

	return;
}



void  CameraActionData::run(const CameraActionID& _id)
{
	m_cameraActions[(int)_id]->run();
}