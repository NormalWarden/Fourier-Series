#include "pch.h"
#include "CFn.h"

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown)
{
	double x = t;
	double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * Fm * t)) * t); // main function for graph (let it go to hell)
	return CLinTr::Transform(x, y);
}

CPoint CFn::GetPoint2(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown, unsigned int k, bool linView)
{
	countdown = 64;
	double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * Fm * t)) * t);
	double tempRes1 = 0, tempRes2 = 0;
	for (int i = 1; i <= countdown - 1; i++)
	{
		tempRes1 += cos(2 * 3.14 * k * i / countdown);
		tempRes2 += sin(2 * 3.14 * k * i / countdown);
	}
	double xk1 = y * tempRes1 / countdown, xk2 = y * tempRes2 / countdown;
	double result = sqrt(xk1 * xk1 + xk2 * xk2);
	return CLinTr::Transform1(k, result, linView);
}