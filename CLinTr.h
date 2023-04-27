#pragma once

struct ScaleDispl
{
	CPoint point;
	double mX, mY;
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
	CPoint Transform1(double x, double y, bool linView);
	void SetParam(double dmX, double dmY);
	void GetParam(double& dmX, double& dmY);
};

