#pragma once
#include <vector>
#include "CFn.h"
class CPntAr :
    public CFn
{
public:
	CPntAr();
	virtual ~CPntAr();
protected:
	std::vector<CPoint> Points;
public:
	unsigned int CalcPoints(double amplitude, double frequency, double m, unsigned int Fm);
	unsigned int GetPoints(std::vector<CPoint>& in) { in = Points; return (unsigned int)in.size(); }
};

