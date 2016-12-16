#pragma once
#include "OptionSelectUI.h"
#include "PadSelectUI.h"
#include "SoundSelectUI.h"
#include "VolumeSelectUI.h"
#include "Fade.h"

class Option;


class OptionUI
{
public:
	OptionUI();
	~OptionUI();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
	void finish();
	void operation(Option& _opution);
	void outionOperation(Option& _opution);
	void padOperation(Option& _opution);
	void cancel(Option& _opution);
private:
	void createSelect();
private:
	OptionSelectUI m_select;
	PadSelectUI m_pad;
	VolumeSelectUI m_volume;
	SoundSelectUI m_sound;
	Fade m_fade;
	bool m_cahnge;
};