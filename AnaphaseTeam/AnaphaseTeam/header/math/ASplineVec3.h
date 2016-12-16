#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class ASpline;

class ASplineVec3
{
public:
	//コンストラクタ
	ASplineVec3(void);

	//デストラクタ
	~ASplineVec3(void);

	/**
	@brief 初期化
	@param[_sp]
	*/
	void init(const std::vector<GSvector3>& _sp);

	/**
	@brief スプライン曲線の計算
	@param[_t] 0 <= _t < = 要素数
	@return 結果
	*/
	GSvector3 culc(float _t);

private:
	static const int MaxSplineSize;				//配列の最大要素数を先に決めておく

	int m_num;									//要素数を保持するための変数

	std::unique_ptr<ASpline> m_xs, m_ys, m_zs;	//３次スプライン

	std::vector<float> m_x, m_y, m_z;			//３次
};