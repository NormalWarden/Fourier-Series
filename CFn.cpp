#include "pch.h"
#include "CFn.h"

CFn::CFn()
{
}

CFn::~CFn()
{
}

CPoint CFn::GetPoint(double A, double Fi)
{
	double x = sin(A);
	double y = sin(2. * A + Fi);//lissaget
	return CLinTr::Transform(x, y);
}
