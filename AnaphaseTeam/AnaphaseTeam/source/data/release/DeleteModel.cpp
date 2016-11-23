#include "..\..\..\header\data\release\DeleteModel.h"
#include <gslib.h>
void DeleteModel::operator()(unsigned int _id)
{
	gsDeleteMesh(_id);
	gsDeleteAnimation(_id);
	gsDeleteSkeleton(_id);
}
