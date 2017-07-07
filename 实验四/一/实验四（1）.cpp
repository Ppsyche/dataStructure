#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 100
typedef struct 
{
	char *base;
	char *top;
	int stacksize;
}SS;

typedef struct LNode
{
	char a;
	struct LNode *next;
}LN,*LL;

void chushihua(SS &S)
{
	S.base=new char[MAXSIZE];
	if(!S.base) cout<<"初始化失败"<<endl;
	S.top=S.base;
	S.stacksize=MAXSIZE;
}

int shuru(LL L)
{
	char s[100];
	LL q=L;
    cout<<"输入一个字符串（<100）:"<<endl;
	gets(s);
	int len=strlen(s);
    for(int i=0;i<len;i++)
	{
		LL p=new LNode;
		p->next=NULL;
        p->a=s[i];
		q->next=p;
		q=q->next;
	}
	return len;
}

main()
{
	LL L=new LNode;
	L->next=NULL;
	SS S;
	chushihua(S);
	int len=shuru(L);
	//shuchu(L);
	LL p;
	p=L->next;
	for(int i=0;i<(len/2);i++)
	{    
	    if(S.top-S.base==S.stacksize)
		{cout<<"栈已满！！"<<endl;break;}
		*S.top++=p->a;
		p=p->next;
	}
	if(len%2==1)
		p=p->next;
	int t=1;
	for(int j=0;j<(len/2);j++)
	{
		if(p->a!=(*--S.top))
		{t=0;break;}
		p=p->next;
	}
	if(t)
		cout<<"是中心对称字符"<<endl;
	else
		cout<<"不是中心对称字符"<<endl;

}


