#pragma once
#include "CLinTr.h"
class CFn :
    public CLinTr
{
public:
	CFn();
	virtual ~CFn();
	CPoint GetPoint(unsigned int amplitude, float frequency, double m, float t, unsigned int Fm);
};

