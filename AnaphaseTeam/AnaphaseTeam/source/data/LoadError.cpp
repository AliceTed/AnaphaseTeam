#include "../../header/data/LoadError.h"

namespace Data
{
 	void ErrorMessage::operator ()(const std::string& _fileName, const std::string& _dataName)const
	{
		std::string mssage = _fileName + "‚Ì“Ç‚İ‚É¸”s";
		std::string title = _dataName + "‚Ì“Ç‚İƒGƒ‰[";
		MessageBox((HWND)_glutGetHWND(), mssage.c_str(), title.c_str(), MB_OK);
	}
}