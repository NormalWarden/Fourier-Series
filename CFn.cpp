#pragma once
#include "pch.h"
#include "CFn.h"

#define M_PI 3.14159265358979323846
#define Fd 10000000.
#define M	 3.14159126

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown)
{
	double x = t;
	double y = float(amplitude) * sin(2. * M_PI * (float(frequency) + m * sin(2. * M_PI * float(Fm) * t)) * t); // main function for graph (let it go to hell)
	return CLinTr::Transform(x, y);
}

CPoint CFn::GetPoint2(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown, unsigned int k, bool linView)
{
	double N = double(countdown);
	double m1 = double(m);
	double tempRes1 = 0., tempRes2 = 0.;
	double k1 = double(k);
	for (int i = 0; i <= countdown-1; i++)
	{
		double temp = double(i) / Fd;
		double y = double(amplitude) * sin(2. * M_PI * (double(frequency) + m1 * sin(2. * M_PI * double(Fm) * temp)) * temp);
		tempRes1 += y*cos((-2. * M_PI * k1 * double(i)) / (N));
		tempRes2 += y*sin((-2. * M_PI * k1 * double(i)) / (N));
	}
	double xk1 = tempRes1 / N, xk2 = tempRes2 / N;
	double result = sqrt(xk1 * xk1 + xk2 * xk2);
	return CLinTr::Transform1(k, result, linView);
}