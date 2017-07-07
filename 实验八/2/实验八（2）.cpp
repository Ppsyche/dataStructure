#include<iostream>
using namespace std;

#define M 6
typedef int KeyType;
typedef int InfoType;

typedef struct 
{
	KeyType key;
	InfoType other;
}RedType;

typedef struct 
{
	RedType r[M+1];
	int length;
}SqList;

void output(RedType T[])
{
	cout<<"排列后为：";
	for(int i=1;i<=M;i++)
		cout<<T[i].key<<" ";
	cout<<endl;
}

void Merge(RedType R[],RedType T[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	while(i<=mid&&j<=high)
	{
		if(R[i].key<=R[j].key)
			T[k++]=R[i++];
		else
			T[k++]=R[j++];
	}
	while(i<=mid)
		T[k++]=R[i++];
	while(j<=high)
		T[k++]=R[j++];
}

void MSort(RedType R[],RedType T[],int low,int high)
{
	RedType S[M+1];
	if(low==high)
		T[low]=R[low];
	else
	{
		int mid=(low+high)/2;
		MSort(R,S,low,mid);
		MSort(R,S,mid+1,high);	
		Merge(S,T,low,mid,high);
	}
}

void zhongshu(RedType T[])
{
	int p=T[1].key,q=p;
	int n=1,m=1;
	int w[M+1],t=-1;
	w[++t]=p;
	for(int i=2;i<=M;i++)
	{
		if(p==T[i].key)
		    n++;
			
			if(n==m)
			{
				n=1;
				q=p;
				p=T[i].key;
				w[++t]=p;
			}
			else if(n>m)
			{
				m=n;
				n=1;
				q=p;
				p=T[i].key;
				t=-1;
				w[++t]=q;
			}
			else
			{
			    p=T[i].key;
			    n=1;
			}
		
	}
	cout<<"众数为:";
	while(t!=-1)
	{
		q=w[t];t--;
		cout<<q<<" ";

	}
	cout<<"重数为:"<<m<<endl;

}

void qiege(RedType T[],int &l,int &r,int n)
{
	int mid=(n+1)/2;
	for(l=1;l<=n;l++)
	{
		if(T[l].key==T[mid].key)
			break;
	}
	for(r=l+1;r<=n;r++)
	{
		if(T[r].key!=T[mid].key)
			break;
	}

}

void zhongshufz(RedType T[],int &maxnum,int &max,int n)
{
	int l,r;
	qiege(T,l,r,n);
	int mid=(n+1)/2;
	int cnt=r-l;
	if(cnt>maxnum)
	{
		maxnum=cnt;
		max=T[mid].key;
	}
	if(l>maxnum)
		zhongshufz(T,maxnum,max,l);
	if(n-r>maxnum)
		zhongshufz(T+r,maxnum,max,n-r);
}

void MergeSort(SqList &L)
{
	MSort(L.r,L.r,1,L.length);
	output(L.r);
	int max=0,maxnum=0;
	zhongshufz(L.r,maxnum,max,M);
	cout<<"众数为："<<max<<"    重数为："<<maxnum<<endl;
}

main()
{
	SqList L;
	int i;
	cout<<"请输入"<<M<<"个数:";
	for(i=1;i<=M;i++)
	{
		cin>>L.r[i].key;
	}
	L.length=M;
	MergeSort(L);
}
	
