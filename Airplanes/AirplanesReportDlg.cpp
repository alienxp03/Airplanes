// AirplanesReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Airplanes.h"
#include "AirplanesReportDlg.h"


// AirplanesReportDlg dialog

IMPLEMENT_DYNAMIC(AirplanesReportDlg, CDialog)

AirplanesReportDlg::AirplanesReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AirplanesReportDlg::IDD, pParent)
{
}

AirplanesReportDlg::~AirplanesReportDlg()
{
}

void AirplanesReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, REPORT_CTRL, ctrlAirplanesBox);
}


BEGIN_MESSAGE_MAP(AirplanesReportDlg, CDialog)
END_MESSAGE_MAP()


// AirplanesReportDlg message handlers

BOOL AirplanesReportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ctrlAirplanesBox.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 100);
	ctrlAirplanesBox.InsertColumn(1, _T("Profession"), LVCFMT_CENTER, 80);
	ctrlAirplanesBox.InsertColumn(2, _T("Fav. Sport"), LVCFMT_LEFT, 100);
	ctrlAirplanesBox.InsertColumn(3, _T("Hobby"), LVCFMT_LEFT, 80);

	int nItem;	 // This integer will be used to identify the
	// header item we are dealing with.
	// Give a name/caption to an item to display under the first header
	nItem = ctrlAirplanesBox.InsertItem(0, _T("Sandra"));
	// Create a caption for the corresponding headers.
	ctrlAirplanesBox.SetItemText(nItem, 1, _T("Singer"));
	ctrlAirplanesBox.SetItemText(nItem, 2, _T("HandBall"));
	ctrlAirplanesBox.SetItemText(nItem, 3, _T("Beach"));

	nItem = ctrlAirplanesBox.InsertItem(0, _T("Andrew"));
	// Create a caption for the corresponding headers.
	ctrlAirplanesBox.SetItemText(nItem, 1, _T("Dancer"));
	ctrlAirplanesBox.SetItemText(nItem, 2, _T("Chess"));
	ctrlAirplanesBox.SetItemText(nItem, 3, _T("Die"));

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
