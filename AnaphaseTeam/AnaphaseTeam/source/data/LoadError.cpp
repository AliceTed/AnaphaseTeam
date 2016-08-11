#include "../../header/data/LoadError.h"

namespace Data
{
 	void ErrorMessage::operator ()(const std::string& _fileName, const std::string& _dataName)const
	{
		std::string mssage = _fileName + "の読込みに失敗";
		std::string title = _dataName + "の読込みエラー";
		MessageBox((HWND)_glutGetHWND(), mssage.c_str(), title.c_str(), MB_OK);
	}
}