// lerkMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Airplanes.h"
#include "ClerkMenuDlg.h"
#include "AirplanesReportDlg.h"


// ClerkMenuDlg dialog

IMPLEMENT_DYNAMIC(ClerkMenuDlg, CDialog)

ClerkMenuDlg::ClerkMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ClerkMenuDlg::IDD, pParent)
{

}

ClerkMenuDlg::~ClerkMenuDlg()
{
}

void ClerkMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClerkMenuDlg, CDialog)
	ON_BN_CLICKED(AIRPLANES_REPORT_DLG, &ClerkMenuDlg::OnBnClickedReportDlg)
END_MESSAGE_MAP()


// ClerkMenuDlg message handlers

void ClerkMenuDlg::OnBnClickedReportDlg()
{
	EndDialog(0);
	AirplanesReportDlg dlg;
	dlg.DoModal();

}
