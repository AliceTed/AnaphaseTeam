#pragma once

#include "../ui/ScaleImage.h"
#include <vector>
#include <memory>
class IRenderer;
typedef std::shared_ptr<ScaleImage> Image_Ptr;
class PauseUI
{
public:
	PauseUI();
	~PauseUI();
	void initialize();
	void update(float deltaTime);
	void start(int _select);
	void scale_Game(const GSvector2 _def, const GSvector2 _max, const GSvector2 _posi0[], const GSvector2 _posi1[]);
	void draw(IRenderer* _renderer);

private:
	std::vector<Image_Ptr> m_images;
};