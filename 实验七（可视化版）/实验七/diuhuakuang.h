#if !defined(AFX_DIUHUAKUANG_H__D4F1330B_4814_49EA_8D99_93B9ABF158BB__INCLUDED_)
#define AFX_DIUHUAKUANG_H__D4F1330B_4814_49EA_8D99_93B9ABF158BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// diuhuakuang.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// diuhuakuang dialog

class diuhuakuang : public CDialog
{
// Construction
public:
	diuhuakuang(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(diuhuakuang)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(diuhuakuang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(diuhuakuang)
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIUHUAKUANG_H__D4F1330B_4814_49EA_8D99_93B9ABF158BB__INCLUDED_)
