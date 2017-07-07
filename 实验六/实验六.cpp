#include<iostream>
using namespace std;
#define MAX 100
int t=-1,w=1,c=1;


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

SS S;
BT bt[10]={NULL};

void nf(BT T,BT st[],int z);
int panduan1(BT &T,BT ct[],int n);
int panduan2(BT &T);
void shuchu(BT st[]);
int panduan3(BT Q,int z);
int panduan4(BT Q);
void chushihua(SS &S);


void main()
{
	int xz=1;
	while(xz)
	{
		cout<<"请选择遍历方法："<<endl;
		cout<<"1.深度优先"<<endl;
		cout<<"2.广度优先"<<endl;
		cout<<"0.退出"<<endl;
		cin>>xz;
		if(xz==1)
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
		}
		else if(xz==2)
		{	
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
	}

	return;
}

void nf(BT T,BT st[],int z)
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



int panduan1(BT &T,BT ct[],int n)
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

int panduan2(BT &T)
{
	if((T->a[1]==T->a[2]&&T->a[0]!=T->a[1])||(T->a[2]==T->a[3]&&T->a[0]!=T->a[2]))
		return 0;
	return 1;
}

void shuchu(BT st[])
{
	cout<<"方案"<<w<<":"<<endl;
	cout<<" ————————————————————————————"<<endl;
	cout<<"|   步骤   |         南岸         |         北岸        |"<<endl;
	cout<<" ————————————————————————————"<<endl;
	for(int i=0;st[i]!=NULL;i++)
	{
		BT p=st[i];
		cout<<"|     "<<i<<"     |   ";
        if(p->a[0]==0)
			cout<<"农夫 ";
		else
			cout<<"     ";
		if(p->a[1]==0)
			cout<<"狼 ";
		else
			cout<<"   ";
		if(p->a[2]==0)
			cout<<"羊 ";
		else
			cout<<"   ";
		if(p->a[3]==0)
			cout<<"白菜   |   ";
		else
			cout<<"       |   ";
		if(p->a[0]==1)
			cout<<"农夫 ";
		else
			cout<<"     ";
		if(p->a[1]==1)
			cout<<"狼 ";
		else
			cout<<"   ";
		if(p->a[2]==1)
			cout<<"羊 ";
		else
			cout<<"   ";
		if(p->a[3]==1)
			cout<<"白菜   |"<<endl;
		else
			cout<<"       |"<<endl;
		cout<<" ————————————————————————————"<<endl;
	}
	w++;
}


int panduan3(BT Q,int z)
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

int panduan4(BT Q)
{
	for(int i=0;i<c;i++)
	{
		BT p=bt[i];
		if(Q->a[0]==p->a[0]&&Q->a[1]==p->a[1]&&Q->a[2]==p->a[2]&&Q->a[3]==p->a[3])
			return 0;
	}
	return 1;
}

void chushihua(SS &S)
{
	S.b=new BT[MAX];
	if(!S.b) 
		cout<<"失败！";
	S.front=S.rear=0;
}
