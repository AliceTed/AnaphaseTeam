#pragma once
#ifndef _CASTID_H_
#define _CASTID_H_

namespace Data
{
	class CastID
	{
	public:
		template<class ID>
		const unsigned int operator ()(ID _id)const
		{
			return static_cast<unsigned int>(_id);
		}
	};
}
#endif