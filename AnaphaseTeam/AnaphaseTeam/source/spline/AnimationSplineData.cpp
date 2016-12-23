#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "../../header/spline/AnimationSplineData.h"
#include "../../header/spline/SplineVec3.h"
#include "../../header/spline//AnimationSpline.h"
#include "../../header/data/Message.h"

AnimationSplineData::AnimationSplineData(void) :
	m_datas()
{

}

AnimationSplineData::~AnimationSplineData()
{

}

void AnimationSplineData::add(std::string _id, const std::vector<GSvector3>& _points, float _speed)
{
	//�f�[�^����
	m_datas.insert(std::make_pair(_id, std::make_unique<AnimationSpline>()));

	//�X�v���C���Ȑ��̏�����
	m_datas[_id]->init(_points,_speed);

	return;
}

void AnimationSplineData::add(std::string _id, const std::string _fileName)
{
	std::ifstream reading_file;
	std::string reading_line_buffer;
	std::stringstream fileName;
	std::list<GSvector3> vecs;
	std::vector<std::string> sv;
	float speed;
	int i;

	//�f�[�^����
	m_datas.insert(std::make_pair(_id, std::make_unique<AnimationSpline>()));

	fileName << "./res/data/" << _fileName;

	//�t�@�C�����J��
	reading_file.open(fileName.str(), std::ios::in);

	//�t�@�C�����Ȃ���΃G���[���o��
	if (reading_file.fail())
	{
		Message error;
		error(fileName.str(), fileName.str());

		return;
	}

	//�ǂݍ��񂾃t�@�C���̒��g�𕶎���ɂ���i��s�A�P���[�v�j
	while (getline(reading_file, reading_line_buffer))
	{
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);

		//�ǂݍ��񂾕������','��؂�ɂ���
		for (i = 0; std::getline(line_separater, separated_string_buffer, ','); i++)
		{
			sv.emplace_back(separated_string_buffer);
		}
	}

	i = 0;
	while (i < sv.size() - 1)
	{
		std::vector<float> vec(3);

		for (int j = 0; j < 3; j++)
		{
			vec[j] = std::stof(sv[i]);
			i++;
		}

		vecs.emplace_back(vec[0], vec[1], vec[2]);
	}

	speed = std::stof(sv[i]);

	//�ǂݍ��񂾒l��z��ɑ������
	std::vector<GSvector3> points;
	std::list<GSvector3>::iterator itr = vecs.begin();
	for (i = 0; itr != vecs.end(); i++)
	{
		points.emplace_back(*itr);
		itr++;
	}
	
	speed = 1.0f / (60.0f * speed);

	//�X�v���C���Ȑ��̏�����
	m_datas[_id]->init(points, speed);

	//�ǂݍ��񂾃t�@�C�������
	reading_file.close();
}

AnimationSpline* AnimationSplineData::get(std::string _id)
{
	return m_datas[_id].get();
}
