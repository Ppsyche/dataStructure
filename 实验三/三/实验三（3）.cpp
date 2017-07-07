#include <iostream>
using namespace std;

typedef struct DuLNode{
	int data;
	int freq;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*LL;

void shuru(LL L)
{
	LL p;
	p=L;
	int n;
	cout<<"请输入元素的个数：";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		LL q=new DuLNode;
		q->next=NULL;
		q->prior=NULL;
		q->freq=0;
		cout<<"请输入第"<<i+1<<"个元素:";
		cin>>q->data;
		q->prior=p;
		p->next=q;
		p=q;
	}
}

void shuchu(LL L)
{
	LL p;
	cout<<"元素为：";
	for(p=L->next;p!=NULL;p=p->next)
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
}

locate(LL L,int t)
{
	LL p;
	for(p=L->next;p!=NULL;p=p->next)
	{
		if(p->data==t)
			p->freq++;
	}
	LL a,b;
	for(a=L->next;a!=NULL;a=a->next)
	{
		for(b=a->next;b!=NULL;b=b->next)
		{
			if(a->freq<b->freq)
			{
				int w;
				w=a->data;
				a->data=b->data;
				b->data=w;
				w=a->freq;
				a->freq=b->freq;
				b->freq=w;
			}
		}
	}
}

void main()
{
	LL L=new DuLNode;
	L->next=NULL;
	L->prior=NULL;
	L->freq=0;
	shuru(L);
	shuchu(L);
	int flag=1;
	while(flag)
	{
	    cout<<"     功能表"<<endl;
	    cout<<"1.进行LOCATE运算"<<endl;
        cout<<"2.显示顺序"<<endl;
	    cout<<"0.退出"<<endl;
	    int n;
	    cout<<"请输入您要使用的功能：";
	    cin>>n;
	    switch(n)
		{
	    case 1:
	       int t;
	       cout<<"请输入要进行运算的数的值：";
	       cin>>t;
	       locate(L,t);
		   break;
		case 2:
			shuchu(L);
			break;
		case 0:
			flag=0;
		}
	}
}
