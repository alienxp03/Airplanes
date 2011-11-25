#pragma once
#include "afxcmn.h"


// AirplanesReportDlg dialog

class AirplanesReportDlg : public CDialog
{
	DECLARE_DYNAMIC(AirplanesReportDlg)

public:
	AirplanesReportDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AirplanesReportDlg();

// Dialog Data
	enum { IDD = AIRPLANES_REPORT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ctrlAirplanesBox;
	virtual BOOL OnInitDialog();
};
