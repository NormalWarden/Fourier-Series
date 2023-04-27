#include "pch.h"
#include "CPntAr.h"

CPntAr::CPntAr()
{
}

CPntAr::~CPntAr()
{
}

unsigned int CPntAr::CalcPoints(unsigned int amplitude, float frequency, float m, unsigned int Fm, unsigned int countdown)
{
	Points.clear();

	// getting all points for graph (using "t" like time)
	for (float t = 0; t <= countdown / 10; t += 0.1)
	{
		CPoint pt = GetPoint(amplitude, frequency, m, t, Fm, countdown);
		Points.push_back(pt);
	}
	return Points.size();
}

unsigned int CPntAr::CalcPoints2(unsigned int amplitude, float frequency, float m, unsigned int Fm, unsigned int countdown, bool linView)
{
	Points.clear();

	// getting all points for graph (using "t" like time)
	float t = 0;
	for (unsigned int k = 0; k <= countdown; k++)
	{
		CPoint pt;
		pt = GetPoint2(amplitude, frequency, m, t, Fm, countdown, k, linView);
		Points.push_back(pt);
		t += 0.1;
	}
	return Points.size();
}
