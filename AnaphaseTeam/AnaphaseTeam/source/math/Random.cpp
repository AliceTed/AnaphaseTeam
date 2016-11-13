#include "../../header/math/Random.h"
#include <random>
const int Math::Random::operator()(int _min, int _max) const
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> range(_min, _max);
	return range(mt);
}

const float Math::Random::operator()(float _min, float _max) const
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_real_distribution<> range(_min, _max);
	return static_cast<float>(range(mt));
}
