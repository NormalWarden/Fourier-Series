#include "pch.h"
#include "CFn.h"

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(unsigned int amplitude, float frequency, double m, float t, float Fm, unsigned int countdown)
{
	double x = t;
	double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * Fm * t)) * t); // main function for graph (let it go to hell)
	return CLinTr::Transform(x, y);
}

CPoint CFn::GetPoint2(unsigned int amplitude, float frequency, double m, float Fm, unsigned int countdown, int k)
{
	//double x = t;
	//double y = amplitude * sin(2 * 3.14 * (frequency + m * sin(2 * 3.14 * Fm * t)) * t);
	double tempRes1 = 0, tempRes2 = 0;
	for (int i = 0; i <= countdown - 1; i++)
	{
		tempRes1 += cos(2 * 3.14 * k * i / countdown);
		tempRes2 += sin(2 * 3.14 * k * i / countdown);
	}
	double xk1 = amplitude * tempRes1, xk2 = amplitude * tempRes2;
	double result = sqrt(xk1 * xk1 + xk2 * xk2);

	return CLinTr::Transform(k, result);
}