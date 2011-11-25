#pragma once


// ClerkMenuDlg dialog

class ClerkMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(ClerkMenuDlg)

public:
	ClerkMenuDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ClerkMenuDlg();

// Dialog Data
	enum { IDD = CLERK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedReportDlg();
};
