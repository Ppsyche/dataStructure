#include<iostream>
using namespace std; 
  
typedef struct List
{
	char a;
	List *next;
}List,*LL;

void shuru(LL A)
{
	LL p;
	int n;
	p=A;
	cout<<"请输入元素的个数：";
    cin>>n;
	for(int i=0;i<n;i++)
	{
		LL q=new List;
		q->next=A;
		cout<<"请输入第"<<i+1<<"个元素：";
		cin>>q->a;
		p->next=q;
		p=p->next;
	}
}

void shuchu(LL A)
{
	LL p;
	for(p=A;(p->next!=A)&&(p->next!=NULL);p=p->next)
	{
		cout<<p->next->a<<" ";
	}
    cout<<" "<<endl;
}

void fenlei(LL A,LL B,LL C)
{
	LL p,a,b,c;
    a=A;
	b=B;
	c=C;
	p=A->next;
	A->next=NULL;
	while(p!=A)
	{
	    if((p->a>='0')&&(p->a<='9'))
		{
		    b->next=p;
		    b=b->next;
			p=p->next;
		    b->next=B;    
		}
		else if(((p->a>='a')&&(p->a<='z'))||((p->a>='A')&&(p->a<='Z')))
		{
		    c->next=p;
		    c=c->next;
			p=p->next;
		    c->next=C;
		    
		}
		else
		{
			a->next=p;
			a=a->next;
		    p=p->next;
			a->next=A;
		}

	}

}

main()
{
	LL A=new List;
	A->next=NULL;
    LL B=new List;
	B->next=NULL;
	LL C=new List;
	C->next=NULL;
    shuru(A);
	cout<<"您输入的元素为：";
	shuchu(A);
	fenlei(A,B,C);
	cout<<"符号链的元素为：";
	shuchu(A);
	cout<<"数字链的元素为：";
	shuchu(B);
	cout<<"字母链的元素为：";
	shuchu(C);
}