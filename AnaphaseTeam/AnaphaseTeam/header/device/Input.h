#ifndef _INPUT_H_
#define _INPUT_H_
#include <gslib.h>
class Input
{
public:
	Input();
	const GSvector2 velocity()const;
	//êÖïΩ
	const int horizontal()const;
	//êÇíº
	const int vertical()const;

	const bool jumpTrigger()const;
	const bool attackTrigger() const;
	const bool slowAttackTrigger() const;
	const bool quickAttackTrigger()const;
	const bool avoidTrigger()const;
	
	//input?
	const bool move()const;
	const bool walk()const;

	const bool up()const;
	const bool down()const;
	const bool exit()const;

	const bool isJoyTriggerUp() const;
	const bool isJoyTriggerDown() const;
	const bool isJoyTriggerLeft() const;
	const bool isJoyTriggerRight() const;
	const bool isJoyTriggerA() const;
	const bool isJoyTriggerB() const;
	const bool isJoyTriggerX() const;
	const bool isJoyStateX() const;
	const bool isJoyTriggerY() const;
	const bool isJoyTriggerLB() const;
	const bool isJoyTriggerRB() const;
	const bool isJoyStateLB() const;
	const bool isJoyStateRB() const;
	const bool isJoyTriggerBACK() const;
	const bool isJoyTriggerSTART() const;
	const bool isJoyTriggerLeftThrust() const;
	const bool isJoyTriggerRightThrust() const;
	const GSvector2 leftPadAxis() const;
	const GSvector2 rightPadAxis() const;
	const bool isJoyLeftTrigger();
	const bool isJoyRightTrigger();
	const bool isEscapeTrigger()const;
private:
 	bool m_previousLeftTrigger;
	bool m_previousRightTrigger;
};
#endif