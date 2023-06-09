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
	unsigned int CalcPoints(unsigned int amplitude, float frequency, float m, unsigned int Fm, unsigned int countdown);
	unsigned int CalcPoints2(unsigned int amplitude, float frequency, float m, unsigned int Fm, unsigned int countdown, bool linView);
	unsigned int GetPoints(std::vector<CPoint>& in) { in = Points; return (unsigned int)in.size(); }
};

