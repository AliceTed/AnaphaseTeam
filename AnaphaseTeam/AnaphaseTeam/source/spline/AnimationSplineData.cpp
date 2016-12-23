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
	//データ生成
	m_datas.insert(std::make_pair(_id, std::make_unique<AnimationSpline>()));

	//スプライン曲線の初期化
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

	//データ生成
	m_datas.insert(std::make_pair(_id, std::make_unique<AnimationSpline>()));

	fileName << "./res/data/" << _fileName;

	//ファイルを開く
	reading_file.open(fileName.str(), std::ios::in);

	//ファイルがなければエラーを出力
	if (reading_file.fail())
	{
		Message error;
		error(fileName.str(), fileName.str());

		return;
	}

	//読み込んだファイルの中身を文字列にする（一行、１ループ）
	while (getline(reading_file, reading_line_buffer))
	{
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);

		//読み込んだ文字列を','区切りにする
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

	//読み込んだ値を配列に代入する
	std::vector<GSvector3> points;
	std::list<GSvector3>::iterator itr = vecs.begin();
	for (i = 0; itr != vecs.end(); i++)
	{
		points.emplace_back(*itr);
		itr++;
	}
	
	speed = 1.0f / (60.0f * speed);

	//スプライン曲線の初期化
	m_datas[_id]->init(points, speed);

	//読み込んだファイルを閉じる
	reading_file.close();
}

AnimationSpline* AnimationSplineData::get(std::string _id)
{
	return m_datas[_id].get();
}
