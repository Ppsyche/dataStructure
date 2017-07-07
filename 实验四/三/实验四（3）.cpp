#include<iostream>
using namespace std;

typedef struct QNode
{
	int data;
	struct QNode *next;
}QN,*QQ;

typedef struct
{
	QQ rear;
}LQ;

LQ chushihua(LQ &Q)
{
	Q.rear=new QN;
	Q.rear->next=Q.rear;
	return Q;
}

int rudiu(LQ &Q,int &e)
{
	QQ p=new QN;
	p->data=e;
	p->next=Q.rear->next;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

int chudiu(LQ &Q,int &e)
{
	if(Q.rear==Q.rear->next)
		return 0;
	else
	{
		QQ p=Q.rear->next->next;
		e=p->data;
		if(Q.rear==p)
		{
			Q.rear=Q.rear->next;
			Q.rear->next =Q.rear;
		}
		else
	        Q.rear->next->next=p->next;
	    delete p;
	}
	return 1;
}

void shuchu(LQ Q)
{
	if(Q.rear->next==Q.rear)
	{cout<<"队为空！"<<endl;return;}
	for(QQ p=Q.rear->next;p!=Q.rear;p=p->next)
		cout<<p->next->data<<" ";
	cout<<endl;
}

main()
{
	int n,e,a,i,j,flag=1,t;
	LQ Q;
	chushihua(Q);
	while(flag)
	{
	    cout<<"功能表"<<endl;
	    cout<<"1.入队"<<endl;
	    cout<<"2.出队"<<endl;
		cout<<"3.显示队内元素"<<endl;
	    cout<<"0.退出"<<endl;
	    cout<<"请选择：";
	    cin>>a;
		switch(a)
		{
		case 1:
             cout<<"请输入入队元素的个数：";
	         cin>>n;
			 cout<<"请输入"<<n<<"个元素：";
	         for(i=0;i<n;i++)
			 {
		        cin>>e;
	            rudiu(Q,e);
			 }
			 break;
		case 2:
	         cout<<"输入出队元素的个数:";
			 cin>>n;
			 cout<<"出队的元素为：";
           	 for(j=0;j<n;j++)
			 {
		          t=chudiu(Q,e);
				  if(t==0)
				  {cout<<"队为空！"<<endl;break;}
				  else
		              cout<<e<<" ";
			 }
          	 cout<<endl;
			 break;
		case 3:
			cout<<"队内元素为：";
            shuchu(Q);
			break;
		case 0:
			flag=0;
			break;
		}
	}
}

