#include <vector>
#include "pch.h"
#include "Graph.h"
#include "DialogDlg.h"
#define _CRT_SECURE_NO_WARNINGS
BEGIN_MESSAGE_MAP(Graph, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

Graph::Graph(bool upperGraph)
{
	this->upperGraph = upperGraph;
}

Graph::~Graph()
{
}

void Graph::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	CRgn Rgn;
	CPen penB, penG;
	HGDIOBJ pold = dc.SelectObject(penB);
	CDialogDlg* pDlg = (CDialogDlg*)AfxGetMainWnd();
	std::vector<CPoint> Points;
	unsigned int n;
	if (upperGraph)
		n = pDlg->points1.GetPoints(Points);
	else
		n = pDlg->points2.GetPoints(Points);

	GetClientRect(&rc); // getting coordinates of working place

	// limiting place for graph
	Rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
	dc.SelectClipRgn(&Rgn);

	// filling working place
	dc.FillSolidRect(&rc, RGB(254, 254, 254));
	penB.CreatePen(PS_DOT, 1, RGB(0, 0, 168));
	
	// painting X and Y axis
	dc.MoveTo(0, rc.CenterPoint().y);
	dc.LineTo(rc.right, rc.CenterPoint().y);
	dc.MoveTo(0, 0);
	dc.LineTo(0, rc.bottom);

	// creating and choosing pen for painting function
	penG.CreatePen(PS_SOLID, 1, RGB(0, 168, 0));

	// painting start graph
	if (n)
	{
		if (upperGraph)
		{
			for (int i = 1; i < n; i++)
			{
				if ((i % 10) == 0)
				{

					dc.MoveTo(Points[i].x, 90 - 5);
					dc.LineTo(Points[i].x, 90 + 5);
					CString number;
					number.Format(L"%d", i / 10);
					dc.TextOutW(Points[i].x - 10, 100, number);
				}
			}
			dc.SelectObject(penG);
			dc.MoveTo(Points[0]);
			for (int i = 1; i < n; i++)
			{
				dc.LineTo(Points[i]);
			}
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if ((i % 10) == 0)
				{
					dc.MoveTo(Points[i].x, 90 - 5);
					dc.LineTo(Points[i].x, 90 + 5);
					CString number;
					number.Format(L"%d", i );
					dc.TextOutW(Points[i].x - 20, 100, number);
				}
			}
			dc.SelectObject(penG);
			for (int i = 0; i < n; i++)
			{
				dc.MoveTo(Points[i].x, 90);
				dc.LineTo(Points[i]);
			}
		}
	}

	dc.SelectObject(pold);
}