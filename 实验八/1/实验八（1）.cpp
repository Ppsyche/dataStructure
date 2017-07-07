#include<iostream>
using namespace std;

#define M 10
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

void MergeSort(SqList &L)
{
	MSort(L.r,L.r,1,L.length);
	output(L.r);
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
	
