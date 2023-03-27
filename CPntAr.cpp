#include "pch.h"
#include "CPntAr.h"

CPntAr::CPntAr()
{
}

CPntAr::~CPntAr()
{
}

unsigned int CPntAr::CalcPoints(double Fi)
{
	Points.clear();
	for (double a = 0; a <= 2. * 3.14; a += .017)
	{
		CPoint pt = GetPoint(a, Fi);
		Points.push_back(pt);
	}
	return Points.size();
}
