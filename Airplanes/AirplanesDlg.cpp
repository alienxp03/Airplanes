// AirplanesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Airplanes.h"
#include "AirplanesDlg.h"
#include "ManagerMenuDlg.h"
#include "ClerkMenuDlg.h"
#include "Functions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CAirplanesDlg dialog




CAirplanesDlg::CAirplanesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAirplanesDlg::IDD, pParent)
	, txtUsernameID(_T(""))
	, txtPassID(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAirplanesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, txtUsername, txtUsernameID);
	DDX_Text(pDX, txtPassword, txtPassID);
}

BEGIN_MESSAGE_MAP(CAirplanesDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(btnLogin, &CAirplanesDlg::OnBnClickedbtnlogin)
END_MESSAGE_MAP()


// CAirplanesDlg message handlers

BOOL CAirplanesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAirplanesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAirplanesDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAirplanesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAirplanesDlg::OnBnClickedbtnlogin()
{
	UpdateData(TRUE);
	char position;
	CString converter;

	if(txtUsernameID.IsEmpty())
		MessageBox(_T("Username cannot be empty!"),_T("ERROR"),MB_ICONERROR | MB_OK);
	else(txtPassID.IsEmpty())
		MessageBox(_T("Password cannot be empty!"),_T("ERROR"),MB_ICONERROR | MB_OK);
	
	fnConnectDB();
	position = fnLogin(txtUsernameID,txtPassID);
	fnCloseDBConnection();

	EndDialog(0);
	
	if (position == 'M'){
		ManagerMenuDlg dlg;
		dlg.DoModal();
	}
	else if (position == 'C'){	
	
		ClerkMenuDlg dlg;
		dlg.DoModal();
	
	}
	else{
		MessageBox(_T("Wrong username/password!"),_T("Login"),MB_ICONERROR | MB_OK);
		exit(1);
	}
	
	
	//converter.Format(_T("%d"),position);
	//MessageBox(converter,_T("Error"),MB_ICONERROR | MB_OK);
}
