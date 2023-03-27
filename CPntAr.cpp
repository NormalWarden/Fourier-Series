#include "pch.h"
#include "CPntAr.h"

CPntAr::CPntAr()
{
}

CPntAr::~CPntAr()
{
}

unsigned int CPntAr::CalcPoints(double amplitude, double frequency, double m)
{
	Points.clear();
	for (double t = 1; t <= 1000; t += 0.01)
	{
		CPoint pt = GetPoint(amplitude, frequency, m, t);
		Points.push_back(pt);
	}
	return Points.size();
}
