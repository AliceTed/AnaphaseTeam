#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/I_CameraWork.h"

CameraWorkData::CameraWorkData(void) :
	m_cameraWorks()
{

}



CameraWorkData::~CameraWorkData()
{

}



void CameraWorkData::add(
	const E_CameraWorkID _id,
	I_CameraWork* _data)
{
	m_cameraWorks.insert(CameraWork_Map::value_type((int)_id, _data));

	return;
}



I_CameraWork* CameraWorkData::get(const E_CameraWorkID _id)
{
	return m_cameraWorks[(int)_id].get();
}