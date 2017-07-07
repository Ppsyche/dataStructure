// ÊµÑéÆßDlg.h : header file
//

#if !defined(AFX_DLG_H__1C055801_C7C2_4CF3_AE66_20FAA1AB4983__INCLUDED_)
#define AFX_DLG_H__1C055801_C7C2_4CF3_AE66_20FAA1AB4983__INCLUDED_
#include "diuhuakuang.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define maxs 50
/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CButton	m_button1;
	CButton	m_radio;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CComboBox	m_combo3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelendcancelCombo3();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnButton2();
	afx_msg int chushihua(int cost[][maxs]);
	afx_msg void OnButton3();
	afx_msg void chaxun2(int cost[][maxs],int chang,int v1,int v2);
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit2();
	afx_msg CString show(int i);
	afx_msg void chaxun1(int cost[][maxs],int chang,int v1,int v2);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__1C055801_C7C2_4CF3_AE66_20FAA1AB4983__INCLUDED_)
