#pragma once

class DataRelease
{
public:
	template<class Delete>
	void operator(Delete _delete, unsigned int _size)
	{
		for (unsigned int i = 0; i < _size; i++)
		{
			_delete(i);
		}
	}
};