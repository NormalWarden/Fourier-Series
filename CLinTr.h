#pragma once

struct ScaleDispl
{
	double mX, mY;
	CPoint center;
};

class CLinTr
{
public:
	CLinTr();
	virtual ~CLinTr();
protected:
	ScaleDispl sd;
public:
	CPoint Transform(double x, double y);
	CPoint Transform1(double x, double y);
	void SetParam(CPoint center, double dmX, double dmY);
};

