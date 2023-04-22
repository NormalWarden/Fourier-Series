// DialogDlg.cpp : implementation file
//
#include "math.h"
#include "pch.h"
#include "framework.h"
#include "Dialog.h"
#include "DialogDlg.h"
#include "afxdialogex.h"
#include <string>

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
	, amplitude(1)
	, frequency(1000000)
	, countdown(100)
	, m(100000)
	, Fm(100000)
	, x(10)
	, y(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, amplitude);
	DDX_Text(pDX, IDC_EDIT4, frequency);
	DDX_Text(pDX, IDC_EDIT5, countdown);
	DDX_Text(pDX, IDC_EDIT6, m);
	DDX_Text(pDX, IDC_EDIT7, Fm);
	DDX_Control(pDX, IDC_COMBO2, comboBox);
	DDX_Text(pDX, IDC_EDIT3, x);
	DDX_Text(pDX, IDC_EDIT2, y);
}

BEGIN_MESSAGE_MAP(CDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDialogDlg::Calculate)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_EDIT3, &CDialogDlg::xEdit)
	ON_EN_CHANGE(IDC_EDIT2, &CDialogDlg::yEdit)
	ON_EN_CHANGE(IDC_EDIT1, &CDialogDlg::EditEventAmplitude)
	ON_EN_CHANGE(IDC_EDIT4, &CDialogDlg::EditEventFrequency)
	ON_EN_CHANGE(IDC_EDIT5, &CDialogDlg::EditEventCountdown)
	ON_EN_CHANGE(IDC_EDIT6, &CDialogDlg::EditEventM)
	ON_EN_CHANGE(IDC_EDIT7, &CDialogDlg::EditEventFm)
	ON_BN_CLICKED(IDOK3, &CDialogDlg::Save)
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
	
	double scale1 = min(rc.Height() / 2, rc.Width() / 2);
	double scale2 = min(rc.Height() / 2, rc.Width() / 2);
	CPoint point1 = { 0, 90 };
	CPoint point2 = { 0, 90 };

	UpdateData();
	// calculating first graphs (lines)
	points1.SetParam(point1, 50, scale1);
	points1.CalcPoints(amplitude,frequency, m, Fm, countdown);
	points2.SetParam(point2, 5, 90);
	points2.CalcPoints2(amplitude, frequency, m, Fm, countdown);

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

	// updating points
	points1.CalcPoints(amplitude, frequency, m, Fm, countdown);
	points2.CalcPoints2(amplitude, frequency, m, Fm, countdown);

	// repainting
	graph1.Invalidate();
	graph2.Invalidate();
}

void CDialogDlg::xEdit()
{
	UpdateData();
	CRect rc;
	points2.SetParam({ 0,90 }, x/2, 90*y);
	switch (x)
	{
	case(1):
		x = 500;
		break;
	case(2):
		x = 250;
		break;
	case(3):
		x = 160;
		break;
	case(4):
		x = 120;
		break;
	case(5):
		x = 100;
		break;
	case(6):
		x = 80;
		break;
	case(7):
		x = 70;
		break;
	case(8):
		x = 60;
		break;
	case(9):
		x = 55;
		break;
	case(10):
		x = 50;
		break;
	default:
		x *= 1;
		break;
	}
	points1.SetParam({ 0,90 }, x, 90/y);
	Calculate();
}


void CDialogDlg::yEdit()
{
	UpdateData();
	CRect rc;
	points2.SetParam({ 0,90 }, x/2, 90*y);
	switch (x)
	{
	case(1):
		x = 500;
		break;
	case(2):
		x = 250;
		break;
	case(3):
		x = 160;
		break;
	case(4):
		x = 120;
		break;
	case(5):
		x = 100;
		break;
	case(6):
		x = 80;
		break;
	case(7):
		x = 70;
		break;
	case(8):
		x = 60;
		break;
	case(9):
		x = 55;
		break;
	case(10):
		x = 50;
		break;
	default:
		x *= 1;
		break;
	}
	points1.SetParam({0,90}, x, 90 / y);
	Calculate();
}

void CDialogDlg::EditEventAmplitude()
{
	Calculate();
}


void CDialogDlg::EditEventFrequency()
{
	Calculate();
}


void CDialogDlg::EditEventCountdown()
{
	Calculate();
}


void CDialogDlg::EditEventM()
{
	Calculate();
}


void CDialogDlg::EditEventFm()
{
	Calculate();
}


void CDialogDlg::Save()
{
	CWindowDC dcG1(&graph1), dcG2(&graph2);
	CRect rc1, rc2;
	graph1.GetClientRect(&rc1);
	graph2.GetClientRect(&rc2);
	CDC dcBmp1, dcBmp2;
	dcBmp1.CreateCompatibleDC(&dcG1);
	dcBmp2.CreateCompatibleDC(&dcG2);
	CBitmap bmp1, bmp2;
	bmp1.CreateCompatibleBitmap(&dcG1, rc1.Width(), rc1.Height());
	bmp2.CreateCompatibleBitmap(&dcG2, rc2.Width(), rc2.Height());
	HGDIOBJ pOld1 = dcBmp1.SelectObject(bmp1);
	HGDIOBJ pOld2 = dcBmp2.SelectObject(bmp2);
	dcBmp1.BitBlt(0, 0, rc1.Width(), rc1.Height(), &dcG1, 0, 0, SRCCOPY);
	dcBmp2.BitBlt(0, 0, rc2.Width(), rc2.Height(), &dcG2, 0, 0, SRCCOPY);
	dcBmp1.SelectObject(pOld1);
	dcBmp2.SelectObject(pOld2);
	std::wstring sFilter = _T("BMP files (*.bmp)|*.bmp||");
	CFileDialog fl1(FALSE, _T(".bmp"), NULL, 6UL, sFilter.c_str());
	CFileDialog fl2(FALSE, _T(".bmp"), NULL, 6UL, sFilter.c_str());
	if (fl1.DoModal() && fl2.DoModal())
	{
		CImage im1, im2;
		im1.Attach(bmp1);
		im2.Attach(bmp2);
		std::wstring pathP1 = fl1.GetOFN().lpstrFile;
		std::wstring pathP2 = fl2.GetOFN().lpstrFile;
		HRESULT hr1 = im1.Save(pathP1.c_str());
		HRESULT hr2 = im2.Save(pathP2.c_str());
	}
}
