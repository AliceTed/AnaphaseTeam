#pragma once
#include "IPlayUI.h"
#include <vector>
#include<unordered_map>
#include <memory>
class IRenderer;
typedef std::shared_ptr<IPlayUI> UI_Ptr;

enum class EUI
{
	HP,
	GAUGE,
	SPICON,
	SIZE
};



class UIManager
{
public:
	static UIManager& getInstance();
	void release(EUI _key);
	~UIManager()=default;
	void add(EUI _key,UI_Ptr _ui);
	void update(float deltatime);
	void draw(IRenderer *_renderer);
private:
	UIManager()
		:m_UIContainer(),m_UI()
	{

	}
	 std::vector<UI_Ptr> m_UIContainer;
	 std::unordered_map<EUI,UI_Ptr> m_UI;
};