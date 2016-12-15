/**
@file Spline.h
@brief スプライン曲線
@author Yuuho Aritomi
@date 2016/12/15
*/

#include <vector>

class ASpline
{
public:
	//コンストラクタ
	ASpline(void);

	//デストラクタ
	~ASpline();

	/**
	@brief 初期化
	@param[_sp]
	*/
	void init(const std::vector<float>& _sp);

	/**
	@brief スプライン曲線の計算
	@param[_t] 0 <= _t < = 要素数
	@return 結果
	*/
	float culc(float _t);

protected:
	static const int MaxSplineSize;			//配列の最大要素数を先に決めておく

private:

	int m_num;								//要素数を保持するための変数
	std::vector<float> m_a, m_b, m_c, m_d;	//ごめんよくわからない
};