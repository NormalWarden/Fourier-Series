#include "pch.h"
#include "CLinTr.h"
#include "math.h"

CLinTr::CLinTr()
{
}

CLinTr::~CLinTr()
{
}

CPoint CLinTr::Transform(double x, double y)
{
	CPoint pt;
	pt.y = (long)(floor(-y * sd.mY + .5)) + 90;
	pt.x = (long)(floor(x * sd.mX + .5));
	return pt;
}

CPoint CLinTr::Transform1(double x, double y, bool linView)
{
	CPoint pt;
	pt.x = (long)(floor(x * sd.mX + .5));
	if (linView)
		pt.y = (long)(floor(-y * sd.mY + .5)) + 180;
	else
		pt.y = -log10(y) + 180;
	return pt;
}

void CLinTr::SetParam(double dmX, double dmY)
{
	sd.mX = dmX;
	sd.mY = dmY;
}

void CLinTr::GetParam(double& dmX, double& dmY)
{
	dmX = sd.mX;
	dmY = sd.mY;
}