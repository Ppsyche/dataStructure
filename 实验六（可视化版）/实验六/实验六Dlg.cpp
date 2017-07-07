// 实验六Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "实验六.h"
#include "实验六Dlg.h"
#define MAX 100
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int t=-1,w=0,c=1;
BT ct[100]={NULL};
SS S;
BT bt[10]={NULL};

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_LIST2, m_ctllist2);
	DDX_Control(pDX, IDC_SHENDU, m_shendu);
	DDX_Control(pDX, IDC_LIST1, m_ctllist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_SHENDU, OnShendu)
	ON_BN_CLICKED(ID_GUANGDU, OnGuangdu)
	ON_BN_CLICKED(IDC_qingping, Onqingping)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
    
	// TODO: Add your control notification handler code here
	DWORD dwStyle = m_ctllist.GetExtendedStyle();                    //添加列表框的网格线！！！
    dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES;                
    m_ctllist.SetExtendedStyle(dwStyle);

	m_ctllist.InsertColumn(0,"步骤",LVCFMT_CENTER,40);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
    m_ctllist.InsertColumn(1,"南岸",LVCFMT_CENTER,120);
    m_ctllist.InsertColumn(2,"北岸",LVCFMT_CENTER,120); 


//	*pResult = 0;
}

void CMyDlg::OnShendu() 
{
	BT T=new BTN;
	BT st[100]= {NULL};
	T->a[0]=0;
	T->a[1]=0;
	T->a[2]=0;
	T->a[3]=0;
	st[++t]=T;
	nf(T->nf,st,0);
	nf(T->nfl,st,1);
	nf(T->nfy,st,2);
	nf(T->nfb,st,3);
    for(int i=0;st[i]!=NULL;i++)
	     st[i]=NULL;
	t=-1;w=0;
}


void CMyDlg::nf(BT T,BT st[],int z)
{
	int n=t;
	T=new BTN;
	BT p=st[n];
	n--;
	T->a[0]=p->a[0];
	T->a[1]=p->a[1];
	T->a[2]=p->a[2];
	T->a[3]=p->a[3];
	if(T->a[0]==0)
	{
        T->a[0]=1;
		if(z==1)
		{
			if(T->a[1]==0)
				T->a[1]=1;
			else
				return;
		}
		if(z==2)
		{
			if(T->a[2]==0)
				T->a[2]=1;
			else
				return;
		}
		if(z==3)
		{
			if(T->a[3]==0)
				T->a[3]=1;
			else
				return;
		}
	}
	else if(T->a[0]==1)
	{
        T->a[0]=0;
		if(z==1)
		{
			if(T->a[1]==1)
				T->a[1]=0;
			else
				return;
		}
		if(z==2)
		{
			if(T->a[2]==1)
				T->a[2]=0;
			else
				return;
		}
		if(z==3)
		{
			if(T->a[3]==1)
				T->a[3]=0;
			else
				return;
		}
	}
	int q=panduan1(T,st,n);
    if(q==0)
	   return;
	else
	{
	    if(T->a[0]+T->a[1]+T->a[2]+T->a[3]==4)
		{
			st[++t]=T;
		    shuchu(st);
			t--;
		    return;
		}
		q=panduan2(T);
		if(q==0)
			return;
		st[++t]=T;
		nf(T->nf,st,0);
	    nf(T->nfl,st,1);
       	nf(T->nfy,st,2);
	    nf(T->nfb,st,3);
	    t--;
	}
}



int CMyDlg::panduan1(BT &T,BT ct[],int n)
{
	BT p;
	while(n>=0)
	{
	     p=ct[n--];
	     if(T->a[0]==p->a[0]&&T->a[1]==p->a[1]&&T->a[2]==p->a[2]&&T->a[3]==p->a[3])
			 return 0;
	}
	 return 1;
}

int CMyDlg::panduan2(BT &T)
{
	if((T->a[1]==T->a[2]&&T->a[0]!=T->a[1])||(T->a[2]==T->a[3]&&T->a[0]!=T->a[2]))
		return 0;
	return 1;
}

void CMyDlg::shuchu(BT st[])
{
		for(int i=0;st[i]!=NULL;i++)
		{
		BT p=st[i];
		switch(i)
		{
		case 0:m_ctllist.InsertItem(i,_T("0"));break;
		case 1:m_ctllist.InsertItem(i,_T("1"));break;
		case 2:m_ctllist.InsertItem(i,_T("2"));break;
		case 3:m_ctllist.InsertItem(i,_T("3"));break;
		case 4:m_ctllist.InsertItem(i,_T("4"));break;
		case 5:m_ctllist.InsertItem(i,_T("5"));break;						
		case 6:m_ctllist.InsertItem(i,_T("6"));break;								
		case 7:m_ctllist.InsertItem(i,_T("7"));break;								
		}
		if(p->a[0]==0&&p->a[1]==0&&p->a[2]==0&&p->a[3]==0)//0000
		{m_ctllist.SetItemText(i,1, _T("农夫 狼 羊 白菜"));
		 m_ctllist.SetItemText(i,2, _T("               "));
		}
		else if(p->a[0]==0&&p->a[1]==0&&p->a[2]==0&&p->a[3]==1)//0001
		{m_ctllist.SetItemText(i,1, _T("农夫 狼 羊     "));
		 m_ctllist.SetItemText(i,2, _T("           白菜"));
		}
		else if(p->a[0]==0&&p->a[1]==0&&p->a[2]==1&&p->a[3]==0)//0010
		{m_ctllist.SetItemText(i,1, _T("农夫 狼    白菜"));
		 m_ctllist.SetItemText(i,2, _T("        羊     "));
		}
		else if(p->a[0]==0&&p->a[1]==1&&p->a[2]==0&&p->a[3]==0)//0100
		{m_ctllist.SetItemText(i,1, _T("农夫    羊 白菜"));
		 m_ctllist.SetItemText(i,2, _T("     狼        "));
		}
		else if(p->a[0]==0&&p->a[1]==1&&p->a[2]==0&&p->a[3]==1)//0101
		{m_ctllist.SetItemText(i,1, _T("农夫    羊     "));
		 m_ctllist.SetItemText(i,2, _T("     狼    白菜"));
		}
		else if(p->a[0]==1&&p->a[1]==0&&p->a[2]==1&&p->a[3]==0)//1010
		{m_ctllist.SetItemText(i,1, _T("     狼    白菜"));
		 m_ctllist.SetItemText(i,2, _T("农夫    羊     "));
		}
		else if(p->a[0]==1&&p->a[1]==0&&p->a[2]==1&&p->a[3]==1)//1011
		{m_ctllist.SetItemText(i,1, _T("     狼        "));
		 m_ctllist.SetItemText(i,2, _T("农夫    羊 白菜"));
		}
		else if(p->a[0]==1&&p->a[1]==1&&p->a[2]==0&&p->a[3]==1)//1101
		{m_ctllist.SetItemText(i,1, _T("        羊     "));
		 m_ctllist.SetItemText(i,2, _T("农夫 狼    白菜"));
		}
		else if(p->a[0]==1&&p->a[1]==1&&p->a[2]==1&&p->a[3]==0)//1110
		{m_ctllist.SetItemText(i,1, _T("           白菜"));
		 m_ctllist.SetItemText(i,2, _T("农夫 狼 羊     "));
		}
		else if(p->a[0]==1&&p->a[1]==1&&p->a[2]==1&&p->a[3]==1)//1111
		{m_ctllist.SetItemText(i,1, _T("               "));
		 m_ctllist.SetItemText(i,2, _T("农夫 狼 羊 白菜"));
		}
	}

	m_ctllist.InsertItem(i,_T(" "));
		m_ctllist.InsertItem(i,_T(" "));

}



void CMyDlg::OnGuangdu() 
{
	// TODO: Add your control notification handler code here
	int e=0;
	chushihua(S);
	BT B=new BTN;
	B->a[0]=0;
    B->a[1]=0;
    B->a[2]=0;
    B->a[3]=0;
	bt[0]=B;
	S.b[S.rear]=B;
	S.rear++;
	while(S.rear!=S.front)
	{
		e=0;
		e=panduan3(B->nf,0);  
		if(e==1)
			goto GOTO;
		e=panduan3(B->nfl,1);
		if(e==1)
			goto GOTO;
		e=panduan3(B->nfy,2);
		if(e==1)
			goto GOTO;
		e=panduan3(B->nfb,3);
GOTO:           if(e==0)
			S.front++;
	}
	shuchu(bt);
}

int CMyDlg::panduan3(BT Q,int z)
{
	BT B=S.b[S.front];
	Q=new BTN;
	Q->a[0]=B->a[0];
	Q->a[1]=B->a[1];
	Q->a[2]=B->a[2];
	Q->a[3]=B->a[3];
	if(Q->a[0]==0)
	{
        Q->a[0]=1;
		if(z==1)
		{
			if(Q->a[1]==0)
				Q->a[1]=1;
			else
				return 0;
		}
		if(z==2)
		{
			if(Q->a[2]==0)
				Q->a[2]=1;
			else
				return 0;
		}
		if(z==3)
		{
			if(Q->a[3]==0)
				Q->a[3]=1;
			else
				return 0;
		}
	}
	else if(Q->a[0]==1)
	{
        Q->a[0]=0;
		if(z==1)
		{
			if(Q->a[1]==1)
				Q->a[1]=0;
			else
				return 0;
		}
		if(z==2)
		{
			if(Q->a[2]==1)
				Q->a[2]=0;
			else
				return 0;
		}
		if(z==3)
		{
			if(Q->a[3]==1)
				Q->a[3]=0;
			else
				return 0;
		}
	}
	int q=panduan4(Q);
    if(q==0)
	   return 0;
	else
	{
		q=panduan2(Q);
		if(q==0)
			return 0;
	}
	S.front++;
	S.b[S.rear]=Q;
	S.rear++;
	bt[c]=Q;
	c++;
	return 1;
}

int CMyDlg::panduan4(BT Q)
{
	for(int i=0;i<c;i++)
	{
		BT p=bt[i];
		if(Q->a[0]==p->a[0]&&Q->a[1]==p->a[1]&&Q->a[2]==p->a[2]&&Q->a[3]==p->a[3])
			return 0;
	}
	return 1;
}

void CMyDlg::chushihua(SS &S)
{
	S.b=new BT[MAX];
	if(!S.b) 
		//cout<<"失败！";
		return;
	S.front=S.rear=0;
}

void CMyDlg::Onqingping() 
{
	// TODO: Add your control notification handler code here
	m_ctllist.DeleteAllItems();
}
