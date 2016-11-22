/*
*
*/

#ifndef _ISCENE_H_
#define _ISCENE_H_
#include "SceneMode.h"
class Renderer;
class IScene
{
public:
	virtual ~IScene(){}
	virtual void initialize() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(const Renderer& renderer)=0;
	virtual void finish()=0;
	virtual const SceneMode next()const=0;
	virtual const bool isEnd()const=0;
	virtual const bool isExit()const = 0;
}; 
#endif