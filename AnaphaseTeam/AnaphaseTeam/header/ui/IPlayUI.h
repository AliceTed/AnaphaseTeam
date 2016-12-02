#pragma once
class IRenderer;
class IPlayUI
{
public:
	virtual ~IPlayUI() {};
	virtual void update(float deltaTime) = 0;
	virtual void draw(IRenderer *_renderer) = 0;
};