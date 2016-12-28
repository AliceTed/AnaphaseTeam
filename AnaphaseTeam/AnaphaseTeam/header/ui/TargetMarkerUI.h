#pragma once
#include "IPlayUI.h"
#include <gslib.h>
class Status;
class Player;

class TargetMarkerUI : public IPlayUI
{
public:
	TargetMarkerUI(const GSvector3 & _position, Player* _player);
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private :
	GSvector3 transform(IRenderer* _renderer);
private:
	GSvector3 m_position;
	Player* m_player;
	float m_scale;
};