
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

	// input variables
	unsigned int amplitude;
	float frequency;
	float m;
	unsigned int countdown;
	float Fm;

	// graphs for function
	Graph graph1 = true;
	Graph graph2 = false;

	// variables for containing points for graph1 and graph2
	CPntAr points1;
	CPntAr points2;

	// place for choosing linear of logarithmic view
	CComboBox comboBox;
	afx_msg void xEdit();
	afx_msg void yEdit();
	unsigned int x;
	unsigned int y;
	afx_msg void EditEventAmplitude();
	afx_msg void EditEventFrequency();
	afx_msg void EditEventCountdown();
	afx_msg void EditEventM();
	afx_msg void EditEventFm();
	afx_msg void Save();
};