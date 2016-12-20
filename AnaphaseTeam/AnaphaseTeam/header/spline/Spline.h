/**
@file Spline.h
@brief スプライン曲線
@author Yuuho Aritomi
@date 2016/12/15
*/

#include <vector>
#include <gslib.h>

class Spline
{
public:
	//コンストラクタ
	Spline(void);

	//デストラクタ
	~Spline();

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
	float culc(float _t, int _num);

	/**
	@return アニメーションが終了したか？
	*/
	bool isEnd(void);

private:
	static const int MaxSplineSize;			//配列の最大要素数を先に決めておく

	int m_num;								//要素数を保持するための変数

	std::vector<float> m_a, m_b, m_c, m_d;	//ごめんよくわからない

	bool m_isEnd;							//アニメーションが終了したか？
};