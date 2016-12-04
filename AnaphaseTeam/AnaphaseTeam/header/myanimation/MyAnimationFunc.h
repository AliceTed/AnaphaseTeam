#pragma once
#include "MYANIMATION_MODE.h"
struct Transform;
void startMyAnimation(unsigned int _index, Transform* _target, MYANIMATION_MODE _mode = MYANIMATION_MODE::DEDAULT);
void updateMyAnimation(unsigned int _index, float deltaTime);
const bool isEndMyAnimation(unsigned int _index);