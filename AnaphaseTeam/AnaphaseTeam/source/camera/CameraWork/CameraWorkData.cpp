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
	E_CameraWorkID _id,
	I_CameraWork* _data)
{
	//カメラワーク追加
	m_cameraWorks.insert(std::make_pair(_id, CameraWork_Ptr(_data)));

	return;
}

I_CameraWork* CameraWorkData::get(const E_CameraWorkID _id)
{
	//指定したＩＤのカメラワークを返す
	return m_cameraWorks[_id].get();
}