#include "pch.h"
#include "CLinTr.h"

CLinTr::CLinTr()
{
}

CLinTr::~CLinTr()
{
}

CPoint CLinTr::Transform(double x, double y)
{
	CPoint pt;
	pt.y = (long)(floor(-y * sd.mY + .5)) + sd.mY;
	pt.x = (long)(floor(x * sd.mX + .5));
	return pt;
}

void CLinTr::SetParam(CPoint center, double dmX, double dmY)
{
	sd.center = center;
	sd.mX = dmX;
	sd.mY = dmY;
}
