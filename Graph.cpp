#include <vector>
#include "pch.h"
#include "Graph.h"
#include "DialogDlg.h"
#define _CRT_SECURE_NO_WARNINGS
BEGIN_MESSAGE_MAP(Graph, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	CPen penB, penG;
	HGDIOBJ pold = dc.SelectObject(penB);
	CDialogDlg* pDlg = (CDialogDlg*)AfxGetMainWnd();
	std::vector<CPoint> Points;
	unsigned int n = pDlg->points1.GetPoints(Points);

	GetClientRect(&rc); // getting coordinates of working place

	// filling working place
	dc.FillSolidRect(&rc, RGB(254, 254, 254));
	penB.CreatePen(PS_DOT, 1, RGB(0, 0, 168));
	
	// painting X and Y axis
	dc.MoveTo(0, rc.CenterPoint().y);
	dc.LineTo(rc.right, rc.CenterPoint().y);
	dc.MoveTo(rc.CenterPoint().x, 0);
	dc.LineTo(rc.CenterPoint().x, rc.bottom);

	// creating and choosing pen
	penG.CreatePen(PS_SOLID, 1, RGB(0, 168, 0));
	dc.SelectObject(penG);

	if (n)
	{
		dc.MoveTo(Points[0]);
		for (int i = 1; i < n; i++)
			dc.LineTo(Points[i]);
	}

	dc.SelectObject(pold);
}