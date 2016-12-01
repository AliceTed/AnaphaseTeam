#pragma once
class ISpecialSkill
{
public:
	virtual ~ISpecialSkill() {}

	virtual void start() = 0;
	virtual void update(float) = 0;
	virtual const bool isEnd() const= 0;
	virtual const float consumption()const = 0;
};