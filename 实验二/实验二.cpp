#include <iostream>
#include <stdlib.h>
using namespace std; 

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void chushihua(LinkList *L)
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL;
}

void shuchu(LinkList L)
{
	LNode *r;
	r=L;
	cout<<"元素为：";
	for(;r->next!=NULL;r=r->next)
	    cout<<r->next->data<<" ";
	cout<<endl;
}

void paixu(LinkList L)
{
	LNode *m,*n;
	for(m=L->next;m->next!=NULL;m=m->next)
	{
		for(n=m->next;n!=NULL;n=n->next)
		{
			if((m->data)>(n->data))
			{
				int t=m->data;
				m->data=n->data;
				n->data=t;
			}
		}
	}
}

void shuru(LinkList L)
{
	int n;
	LNode *p,*r;
	cout<<"请输入元素的个数：";
	cin>>n;
	r=L;
	for(int i=0;i<n;i++)
	{
		p = (LNode *)malloc(sizeof(LNode));
    
		p->next=NULL;
		cout<<"请输入第"<<i+1<<"个元素：";
		cin>>p->data;
		r->next=p;
		r=p;
	}
	paixu(L);
}

void tianjia(LinkList L)
{
	LNode *r,*p;
	int f=1;
	r=L;
    p = (LNode *)malloc(sizeof(LNode));
	p->next=NULL;
	cout<<"请输入您要插入的元素：";
	cin>>p->data;
	for(r;r->next!=NULL;r=r->next)
	{
		if(p->data<=r->next->data)
		{
		    p->next=r->next;
			r->next=p;
			f=0;
			break;
		}
	}
	if(f)
		r->next=p;
	shuchu(L);
}

void nizhi(LinkList L)
{
	LNode *p,*q,*r;
	int flag=1;
	if((L!=NULL)&&(L->next!=NULL))
	{
		p=L->next;
		q=p->next;
		r=q->next;
		for(;r!=NULL;p=q,q=r,r=r->next)
		{
			if(flag==1)
			{p->next=NULL;flag=0;}
			q->next=p;
			L->next=q;
		}
		q->next=p;
		L->next=q;
	}
	shuchu(L);
}

void hebing(LinkList L)
{
	LNode *A;
	chushihua(&A);
	shuru(A);
	cout<<"表一";
	shuchu(L);
	cout<<"表二";
	shuchu(A);
	LNode *C;
	chushihua(&C);
	LNode *p,*q,*r;
	p=L->next;
	q=A->next;
	r=C;
    while(p&&q)
	{
        if((p->data)<=(q->data))
		{
			r->next=p;
			p=p->next;
		}
		else
		{
			r->next=q;
			q=q->next;
		}
		r=r->next;
	}
	if(p!=NULL)
		r->next=p;
	if(q!=NULL)
		r->next=q;
	nizhi(C);
	free(A);
	free(L);
}





main()
{
	LNode *L;
	int flag=1;
	char a;
	chushihua(&L);
    shuru(L);
	shuchu(L);
	while(flag)
	{
	    cout<<"     功能表"<<endl;
	    cout<<"1.为链表添加元素"<<endl;
	    cout<<"2.将链表逆置"<<endl;
	    cout<<"3.新建一链表，并将俩链合并"<<endl;
	    cout<<"0.退出"<<endl;
	    cout<<"请选择您要进行的项目：";
	    cin>>a;
	    switch(a)
		{
	     case '1':tianjia(L);break;
		 case '2':nizhi(L);break;
		 case '3':hebing(L);break;
		 case '0':flag=0;break;
		 default:cout<<"输入有误，请重新输入！"<<endl;
		}
	}
}