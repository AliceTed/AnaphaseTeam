#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "../../header/spline/AnimationSplineData.h"
#include "../../header/spline/SplineVec3.h"
#include "../../header/spline//AnimationSpline.h"
#include "../../header/spline/SPLINE_ANIMATION_ID.h"
#include "../../header/data/Message.h"

AnimationSplineData::AnimationSplineData(void) :
	m_datas()
{

}

AnimationSplineData::~AnimationSplineData()
{

}

void AnimationSplineData::add(SPLINE_ANIMATION_ID _id, const std::vector<GSvector3>& _points)
{
	//データ生成
	m_datas.insert(std::make_pair(_id, std::make_unique<AnimationSpline>()));

	//スプライン曲線の初期化
	m_datas[_id]->init(_points);

	return;
}

void AnimationSplineData::add(SPLINE_ANIMATION_ID _id, const std::string _fileName)
{
	std::ifstream reading_file;
	std::string reading_line_buffer;
	std::stringstream fileName;
	std::list<GSvector3> vecs;
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
		std::vector<float> vec(3);
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);

		//読み込んだ文字列を','区切りにする
		for (i = 0; std::getline(line_separater, separated_string_buffer, ','); i++)
		{
			vec[i] = std::stof(separated_string_buffer);
		}

		vecs.emplace_back(vec[0], vec[1], vec[2]);
	}

	//読み込んだ値を配列に代入する
	std::vector<GSvector3> points(vecs.size());
	std::list<GSvector3>::iterator itr = vecs.begin();
	for (i = 0; itr != vecs.end(); i++)
	{
		points[i] = (*itr);
		itr++;
	}

	//スプライン曲線の初期化
	m_datas[_id]->init(points);

	//読み込んだファイルを閉じる
	reading_file.close();
}

void AnimationSplineData::resetTime(void)
{
	std::map<SPLINE_ANIMATION_ID, std::unique_ptr<AnimationSpline>>::iterator itr = m_datas.begin();

	while (itr != m_datas.end())
	{
		itr->second->resetTime();
	}
}

AnimationSpline* AnimationSplineData::get(SPLINE_ANIMATION_ID _id)
{
	return m_datas[_id].get();
}
