#include "function/Shake.h"
#include "spline/AnimationSpline.h"
#include "math/AMath.h"
#include <random>

//デフォルトコンストラクタ
Shake::Shake() :
	animSpline(std::make_unique<AnimationSpline>())
{
	init(GSvector3(0.f, 0.f, 0.f), 0, GSvector3(0.f, 0.f, 0.f));
}

//デストラクタ
Shake::~Shake()
{

}

//初期化
void Shake::init(const GSvector3 & _scale, const int _time, const GSvector3 & _center)
{
	std::vector<GSvector3> points(_time);
	std::random_device rnd;	
	std::mt19937 mt(rnd());	
	int i;

	//タイマーの数だけスプライトを用意
	for (i = 0; i < _time - 1; i++)
	{
		//(-_scale ~ _scale)の範囲で３次元ベクトルの成分をランダム生成
		std::uniform_real_distribution<> randX(-_scale.x, _scale.x);
		std::uniform_real_distribution<> randY(-_scale.y, _scale.y);
		std::uniform_real_distribution<> randZ(-_scale.z, _scale.z);

		//ランダム生成された３次元ベクトルを格納
		points[i] = GSvector3(randX(mt), randY(mt), randZ(mt));
	}
	//最後は必ず０になる
	points[i] = GSvector3(0.0f, 0.0f, 0.0f);

	//スプライン曲線の情報の初期化
	animSpline->init(points, 1.f, _center);
}

//実行
GSvector3 Shake::run()
{
	return animSpline->run();
}

//タイマーリセット
void Shake::resetTime(void)
{
	animSpline->resetTime();
}
