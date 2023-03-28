#include "pch.h"
#include "CPntAr.h"

CPntAr::CPntAr()
{
}

CPntAr::~CPntAr()
{
}

unsigned int CPntAr::CalcPoints(double amplitude, double frequency, double m, unsigned int Fm)
{
	Points.clear();
	for (double t = 0; t <= 1000; t += 0.01)
	{
		CPoint pt = GetPoint(amplitude, frequency, m, t, Fm);
		Points.push_back(pt);
	}
	return Points.size();
}
