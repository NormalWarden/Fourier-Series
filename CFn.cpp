#include "pch.h"
#include "CFn.h"

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(double amplitude, double frequency, double m, double t)
{
	double x = t;
	double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * 100 * t) * t));
	return CLinTr::Transform(x, y);
}
