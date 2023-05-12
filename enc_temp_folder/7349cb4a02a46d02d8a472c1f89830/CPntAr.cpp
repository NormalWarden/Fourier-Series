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
	int na;
	for (float t = 0., na=0; na < countdown; t += 1e-7,na++)
	{
		CPoint pt = GetPoint(amplitude, frequency, m, t, Fm, countdown);
		Points.push_back(pt);
		//if (t > 40.)
		//	continue;
	}
	return Points.size();
}

unsigned int CPntAr::CalcPoints2(unsigned int amplitude, float frequency, float m, unsigned int Fm, unsigned int countdown, bool linView)
{
	Points.clear();

	// getting all points for graph (using "t" like time)
	float t = 0.;
	for (unsigned int k = 0; k <= countdown; k++)
	{
		CPoint pt;
		pt = GetPoint2(amplitude, frequency, m, t, Fm, countdown, k, linView);
		Points.push_back(pt);
		t += 0.01;
	}
	return Points.size();
}
