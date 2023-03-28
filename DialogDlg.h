
// DialogDlg.h : header file
//

#pragma once
#include "Graph.h"
#include "CPntAr.h"


// CDialogDlg dialog
class CDialogDlg : public CDialogEx
{
// Construction
public:
	CDialogDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Calculate();
	Graph graph1;
	Graph graph2;
	unsigned int amplitude;
	float frequency;
	double m;
	unsigned int countdown;
	unsigned int Fm;
	CPntAr points1;
	CPntAr points2;
};