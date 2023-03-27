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
	unsigned int CalcPoints(double Fi);
	unsigned int GetPoints(std::vector<CPoint>& in) { in = Points; return (unsigned int)in.size(); }
};

