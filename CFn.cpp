#include "pch.h"
#include "CFn.h"

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(unsigned int amplitude, float frequency, double m, float t, unsigned int Fm)
{
	double x = t;
	double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * Fm * t) * t));
	return CLinTr::Transform(x, y);
}
