#include "pch.h"
#include "CPntAr.h"

CPntAr::CPntAr()
{
}

CPntAr::~CPntAr()
{
}

unsigned int CPntAr::CalcPoints(unsigned int amplitude, float frequency, double m, float Fm, unsigned int countdown)
{
	Points.clear();

	// getting all points for graph (using "t" like time)
	for (float t = 0; t <= countdown; t += 0.1)
	{
		CPoint pt = GetPoint(amplitude, frequency, m, t, Fm, countdown);
		Points.push_back(pt);
	}
	return Points.size();
}

unsigned int CPntAr::CalcPoints2(unsigned int amplitude, float frequency, double m, float Fm, unsigned int countdown)
{
	Points.clear();

	// getting all points for graph (using "t" like time)
	for (int k = 0; k <= countdown; k++)
	{
		CPoint pt;
		pt = GetPoint2(amplitude, frequency, m, Fm, countdown, k);
		Points.push_back(pt);
	}
	return Points.size();
}
