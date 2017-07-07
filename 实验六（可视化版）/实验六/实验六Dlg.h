// ÊµÑéÁùDlg.h : header file
//

#if !defined(AFX_DLG_H__7BBE1D35_F200_4E5E_AC0B_F835ACFFC0D7__INCLUDED_)
#define AFX_DLG_H__7BBE1D35_F200_4E5E_AC0B_F835ACFFC0D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once



#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

typedef struct BTN
{
	int a[4];
	struct BTN *nf,*nfl,*nfy,*nfb;
}BTN,*BT;

typedef struct
{
	BT *b;
	int front;
	int rear;
}SS;

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CListCtrl	m_ctllist2;
	CButton	m_shendu;
	CListCtrl	m_ctllist;
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
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShendu();
	afx_msg void kaishi(BT T,BT st[]);
	afx_msg void nf(BT T,BT st[],int z);
	afx_msg int panduan1(BT &T,BT ct[],int n);
	afx_msg int panduan2(BT &T);
	afx_msg void shuchu(BT st[]);
	afx_msg void shuchu1(BT st[]);
	afx_msg void OnGuangdu();
	afx_msg int panduan3(BT Q,int z);
	afx_msg	int panduan4(BT Q);
	afx_msg void chushihua(SS &S);
	afx_msg void Onqingping();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__7BBE1D35_F200_4E5E_AC0B_F835ACFFC0D7__INCLUDED_)
