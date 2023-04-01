// DialogDlg.cpp : implementation file
//
#include "math.h"
#include "pch.h"
#include "framework.h"
#include "Dialog.h"
#include "DialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define Fd 10000000 // define for calculating points of function

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDialogDlg dialog



CDialogDlg::CDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DIALOG, pParent)
	, amplitude(0)
	, frequency(1000000)
	, countdown(100)
	, m(0)
	, Fm(100000)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, amplitude);
	DDV_MinMaxDouble(pDX, amplitude, 0, 10);				// 0 <= amplitude <= 10
	DDX_Text(pDX, IDC_EDIT4, frequency);
	DDV_MinMaxDouble(pDX, frequency, Fd * 0.1, Fd * 0.4);	// Fd*0.1 <= frequency <= Fd*0.4
	DDX_Text(pDX, IDC_EDIT5, countdown);
	DDV_MinMaxDouble(pDX, countdown, 100, 1000);			// 100 <= countdown <= 1000
	DDX_Text(pDX, IDC_EDIT6, m);
	DDV_MinMaxDouble(pDX, m, 0, frequency / 10);			// 0 <= m <= frequency / 10
	DDX_Text(pDX, IDC_EDIT7, Fm);
	DDV_MinMaxDouble(pDX, Fm, Fd * 0.01, Fd * 0.09);		// Fd*0.01 <= Fm <= Fd*0.09
	DDX_Control(pDX, IDC_COMBO2, comboBox);
}

BEGIN_MESSAGE_MAP(CDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDialogDlg::Calculate)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialogDlg message handlers

BOOL CDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	comboBox.SelectString(0, L"Линейный"); // choosing default value of comboBox

	// linking graphs with its places
	graph1.SubclassDlgItem(IDC_GRAPH1, this);
	graph2.SubclassDlgItem(IDC_GRAPH2, this);

	// getting places (x and y of pixels) of graphs
	CRect rc;
	graph1.GetClientRect(rc);
	graph2.GetClientRect(rc);

	double scale = min(rc.Height() / 2, rc.Width() / 2);

	// calculating first graphs (lines)
	points1.SetParam(rc.CenterPoint(), scale, scale);
	points1.CalcPoints(0,0,0,0);
	points2.SetParam(rc.CenterPoint(), scale, scale);
	points2.CalcPoints(0,0,0,0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDialogDlg::Calculate()
{
	UpdateData(); // updating variables linking with input values
	points1.CalcPoints(amplitude, frequency, m, Fm); // updating points
	graph1.Invalidate(); // repainting
}