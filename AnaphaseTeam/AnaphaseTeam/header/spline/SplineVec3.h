#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class Spline;

class SplineVec3
{
public:
	//コンストラクタ
	SplineVec3(void);

	//デストラクタ
	~SplineVec3(void);

	/**
	@brief 初期化
	@param[_sp]
	*/
	void init(std::vector<GSvector3> _sp);

	/**
	@brief スプライン曲線の計算
	@param[_t] 0 <= _t < = 要素数
	@return 結果
	*/
	GSvector3 culc(float _t);

	/**
	@return アニメーションが終了したか？
	*/
	bool isEnd(void);

private:
	static const int MaxSplineSize;				//配列の最大要素数を先に決めておく

	int m_num;									//要素数を保持するための変数

	std::unique_ptr<Spline> m_xs, m_ys, m_zs;	//３次スプライン

	std::vector<float> m_x, m_y, m_z;			//３次
};