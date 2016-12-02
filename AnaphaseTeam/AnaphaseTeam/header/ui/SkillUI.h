#pragma once
/**
* @file SkillUI.h
* @brief äeskillÇÃUI
* @author èºîˆóTñÁ
* @date 2016/12/02
*/
#include <gslib.h>
#include "../data/id/TEXTURE_ID.h"
#include "../data/id/MYANIMATION_ID.h"
#include "../transform/Transform.h"
class IRenderer;
class SkillUI
{
public:
	SkillUI(const GSvector2& _position,TEXTURE_ID _textureID, MYANIMATION_ID _animationID,const GScolor& _color);
	~SkillUI()=default;
	void initialize();
	void start();
	void rev();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
private:
	TEXTURE_ID m_textureID;
	MYANIMATION_ID m_animationID;
	GScolor m_color;
	GSvector2 m_point;
	Transform m_transform;
};