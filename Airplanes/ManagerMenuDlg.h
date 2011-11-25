#pragma once


// ManagerMenuDlg dialog

class ManagerMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(ManagerMenuDlg)

public:
	ManagerMenuDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ManagerMenuDlg();

// Dialog Data
	enum { IDD = MANAGER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
