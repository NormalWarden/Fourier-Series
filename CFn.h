#pragma once
#include "CLinTr.h"
class CFn :
    public CLinTr
{
public:
	CFn();
	virtual ~CFn();
	CPoint GetPoint(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown);
	CPoint GetPoint2(unsigned int amplitude, unsigned int frequency, float m, float t, unsigned int Fm, unsigned int countdown, unsigned int k, bool linView);
};

