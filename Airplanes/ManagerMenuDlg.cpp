// ManagerMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Airplanes.h"
#include "ManagerMenuDlg.h"


// ManagerMenuDlg dialog

IMPLEMENT_DYNAMIC(ManagerMenuDlg, CDialog)

ManagerMenuDlg::ManagerMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ManagerMenuDlg::IDD, pParent)
{

}

ManagerMenuDlg::~ManagerMenuDlg()
{
}

void ManagerMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ManagerMenuDlg, CDialog)
END_MESSAGE_MAP()


// ManagerMenuDlg message handlers
