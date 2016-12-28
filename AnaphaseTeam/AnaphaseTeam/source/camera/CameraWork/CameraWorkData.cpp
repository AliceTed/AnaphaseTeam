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
	std::string _id,
	I_CameraWork* _data)
{
	//�J�������[�N�ǉ�
	m_cameraWorks.insert(std::make_pair(_id, CameraWork_Ptr(_data)));

	return;
}

I_CameraWork* CameraWorkData::get(std::string _id)
{
	//�w�肵���h�c�̃J�������[�N��Ԃ�
	return m_cameraWorks[_id].get();
}