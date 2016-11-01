#pragma once

class Player;
class AnimatorOne;
class IAttack
{
public:
	~IAttack() {}
	virtual void motion(Player* _player) = 0;
	virtual  void changeMotion(AnimatorOne& _animator, float _speed) = 0;
	virtual const bool isNextAttack(const AnimatorOne& _animator)const = 0;
	virtual const bool isEndMotion(const AnimatorOne& _animator) const = 0;

};