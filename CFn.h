#pragma once
#include "CLinTr.h"
class CFn :
    public CLinTr
{
public:
	CFn();
	virtual ~CFn();
	CPoint GetPoint(double amplitude, double frequency, double m, double t);
};

