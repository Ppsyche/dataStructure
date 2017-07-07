#include<iostream>
using namespace std;
#define arrsize 100

typedef struct
{
	int *elenum;
	int length;
}Sqlist;

bool chuangjian(Sqlist &L)
{
	L.elenum=new int[arrsize];
	if(!L.elenum)
		return false;  
	L.length=0;
	return true;
}

void pailie(Sqlist &L)
{
	for(int i=0;i<L.length;i++)
		cout<<L.elenum[i]<<" ";
	cout<<endl;
}

void shuru(Sqlist &L)
{
	int x;
	GOTO:cout<<"请输入线性表中元素的个数(0-100)：";
    cin>>x;
	if(x>0&&x<=arrsize)
	{
		for(int i=0;i<x;i++)
		{
			cout<<"请输入第"<<i+1<<"个元素:";
			cin>>L.elenum[i];
		}
		L.length=x;
	}
	else
	{
		cout<<"您输入的数字不合法，请重新输入"<<endl;
		goto GOTO;
	}
}

void paixu(Sqlist &L)
{
	for(int i=0;i<L.length-1;i++)
	{
		for(int j=0;j<L.length-1-i;j++)
		{
			if(L.elenum[j]>L.elenum[j+1])
			{
				int t=L.elenum[j];
				L.elenum[j]=L.elenum[j+1];
				L.elenum[j+1]=t;
			}
		}
	}
	pailie(L);

}

void tianjia(Sqlist &L)
{
    int x;
	cout<<"请输入您要添加的元素：";
	cin>>x;
	if((L.length+1)>100)
	{
		cout<<"元素超过限定！！"<<endl;
	}
	else
	{
		L.length++;
		for(int i=L.length-2;i>=0;i--)
		{
			if(x>L.elenum[i])
			{
				L.elenum[i+1]=x;
				break;
			}
			else
				L.elenum[i+1]=L.elenum[i];
		}
		if(x<L.elenum[0])
			L.elenum[0]=x;
	    pailie(L);
	}
}

void youyi(Sqlist &L)
{
	int n;
	cout<<"请输入右移的位数:";
	cin>>n;
	while(n>=L.length)
		n=n-L.length;
	for(;n>0;n--)
	{
		int p=L.elenum[L.length-1];
		for(int i=L.length-1;i>0;i--)
		{
			L.elenum[i]=L.elenum[i-1];
		}
		L.elenum[0]=p;
	}
	pailie(L);
}

void nizhi(Sqlist &L)
{
	for(int i=0,j=L.length-1;i<j;i++,j--)
	{
	    int	p=L.elenum[i];
		L.elenum[i]=L.elenum[j];
		L.elenum[j]=p;
	}
	pailie(L);
}

main()
{
	char c;
	int flag=1;
	Sqlist L;
	chuangjian(L);
	shuru(L);
	paixu(L);
	while(flag)
	{
		GOTO1:cout<<"    功能表"<<endl;
     	cout<<"1.为线性表添加元素"<<endl;
    	cout<<"2.将线性表右移"<<endl;
    	cout<<"3.将线性表逆置"<<endl;
    	cout<<"0.退出"<<endl;
		cin>>c;
		if(c>='0'&&c<='3')
		{
           switch(c)
		   {
		   case'1':tianjia(L);break;
		   case'2':youyi(L);break;
		   case'3':nizhi(L);break;
		   case'0':flag=0;
		   }
		}
		else
		{
			cout<<"您输入的选项不存在，请重新输入！"<<endl;
			goto GOTO1;
		}
	}
} 