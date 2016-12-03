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
	SkillUI(TEXTURE_ID _textureID, MYANIMATION_ID _animationID,const GScolor& _color);
	~SkillUI()=default;
	void initialize();
	void open();
	void close();
	void canSelect();
	void select();
	void update(float deltaTime);
	void draw(IRenderer* _renderer,const GSvector2& _pivot);
	const bool isOpen()const;
private:
	bool m_isOpen;
	TEXTURE_ID m_textureID;
	MYANIMATION_ID m_animationID;
	GScolor m_color;
	GScolor m_selectColor;
	Transform m_transform;
};