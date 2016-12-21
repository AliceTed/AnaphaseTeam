#include "../../header/data/Message.h"
#include <gslib.h>
void Message::operator()(const std::string & _title, const std::string & _message)
{
	MessageBox(NULL, _message.c_str(), _title.c_str(), MB_OK);
}
