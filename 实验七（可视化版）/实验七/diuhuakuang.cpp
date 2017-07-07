// diuhuakuang.cpp : implementation file
//

#include "stdafx.h"
#include "实验七.h"
#include "diuhuakuang.h"
#include"实验七Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// diuhuakuang dialog


diuhuakuang::diuhuakuang(CWnd* pParent /*=NULL*/)
	: CDialog(diuhuakuang::IDD, pParent)
{
	//{{AFX_DATA_INIT(diuhuakuang)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void diuhuakuang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(diuhuakuang)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(diuhuakuang, CDialog)
	//{{AFX_MSG_MAP(diuhuakuang)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// diuhuakuang message handlers

void diuhuakuang::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here


	
}
