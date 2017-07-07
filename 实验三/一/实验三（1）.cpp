#include<iostream>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
}LNode,*LinkList;


void shuru(LinkList L,LinkList s)
{
    int n;
    LNode *p;
    cout<<"请输入元素的个数：";
    cin>>n;
	cout<<"请输入第1个元素：";
	cin>>s->data;
    for(int i=1;i<n;i++)
    {
        p=new LNode;
		cout<<"请输入第"<<i+1<<"个元素：";
        cin>>p->data;
        p->next=L;
		s->next=p;
		s=p;
    }
}

void shuchu(LinkList L,LinkList s)
{
    int i=1;
    LNode *p;
    cout<<"表为";
    for(p=L;p->next!=L;p=p->next)
        cout<<p->data<<" ";
	cout<<p->data;
    cout<<endl;    
    for(p=L;p!=s;p=p->next)
         i++;
    cout<<"s指向第"<<i<<"个结点"<<endl;
    cout<<"s的值为"<<s->data<<endl;                  
}



void main()
{
    LinkList L=new LNode;
	LinkList s;
    int flag=1;
    char n;
    //chushihua(&L);
    s=L;
    shuru(L,s);
    shuchu(L,s);
    while(flag)
    {
         cout<<"1.移动s的位置"<<endl;
         cout<<"2.删除s的直接前驱"<<endl;
         cout<<"0.退出"<<endl;
         cout<<"请选择：";
         cin>>n;
         switch(n)
         {
          case'1':
			  { int t;
              cout<<"请输入s移动的位数:";
              cin>>t;
              for(int i=0;i<t;i++)
                   s=s->next;
			  }
			  shuchu(L,s);break;
          case'2':
			  {
               LNode *r,*p;
               for(r=s,p=r->next;p->next!=s;r=r->next,p=p->next);
			    r->next=s;
                delete p;
				  
			  }
			  
			  shuchu(L,s);break;
          case '0':flag=0;break;
	  default:cout<<"输入有误，请重新输入！"<<endl;
         }
    }
}