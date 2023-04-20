#pragma once
#include "CLinTr.h"
class CFn :
    public CLinTr
{
public:
	CFn();
	virtual ~CFn();
	CPoint GetPoint(unsigned int amplitude, float frequency, double m, float t, float Fm, unsigned int countdown);
	CPoint GetPoint2(unsigned int amplitude, float frequency, double m, float t, float Fm, unsigned int countdown, int k);
};

