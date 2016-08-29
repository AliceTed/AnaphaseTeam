#pragma once
#ifndef _RELEASE_H_
#define _RELEASE_H_
#include "CastID.h"
namespace Data
{
	class Release
	{
	public:
		void operator ()();
	private:
		template<class DeleteFunc, class ID>
		void deleteEach(DeleteFunc deleteFunc, ID size);
	};
	class DeleteModel
	{
	public:
		template<class ID>
		void operator ()(ID _id);
	};
}
#endif
namespace Data
{
	template<class DeleteFunc, class ID>
	void Release::deleteEach(DeleteFunc deleteFunc, ID size)
	{
		CastID cast;
		for (GSuint i = 0; i < cast(size); i++)
		{
			deleteFunc(i);
		}
	}
	template<class ID>
	void DeleteModel::operator()(ID _id)
	{
		CastID cast;
		gsDeleteMesh(cast(_id));
		gsDeleteAnimation(cast(_id));
		gsDeleteSkeleton(cast(_id));
	}
}
