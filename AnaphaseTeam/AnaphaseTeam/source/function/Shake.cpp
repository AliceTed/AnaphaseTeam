#include "../../header/function/Shake.h"
#include "../../header/spline/AnimationSpline.h"
#include "../../header/math/AMath.h"
#include <random>

Shake::Shake(const GSvector3& _scale, float _time) :
	points(_time),
	animSpline(std::make_unique<AnimationSpline>())
{
	std::random_device rnd;		//ランダム本体
	std::mt19937 mt(rnd());		//ランダムに関連した何か
	int i;						//要素数の最後が欲しいので

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
	animSpline->init(points);
}

Shake::~Shake()
{

}

GSvector3 Shake::run(float _speed, const GSvector3& _center)
{
	//アニメーション実行
	return animSpline->run(_speed, _center);
}

void Shake::resetTime(void)
{
	//時間のリセット
	animSpline->resetTime();
}
