#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stdio.h>
#include<conio.h>

using namespace std;

#define maxs 50

void show(int i)
{
	switch(i){
		   case 1: cout<<"校门口";break;
		   case 2: cout<<"体育馆";break;
		   case 3: cout<<"主楼";break;	
		   case 4: cout<<"A区宿舍";break;		
		   case 5: cout<<"游泳馆";break;	
		   case 6: cout<<"联通广场";break;
		   case 7: cout<<"校史馆";break;
		   case 8: cout<<"天天广场";break;	
		   case 9: cout<<"农学楼";break;		
		   case 10: cout<<"A区食堂";break;	
		   case 11: cout<<"实验楼";break;
		   case 12: cout<<"图书馆";break;
		   case 13: cout<<"音乐厅";break;
	   }
}

int chushihua(int cost[][maxs])
{
	int chang,kuan,i,j;
	chang=14;
	kuan=14;
	for(i=1;i<=chang;i++)
		for(j=1;j<=kuan;j++)
			cost[i][j]=9999;
		cost[1][3]=2;
		cost[3][1]=2;
		cost[3][2]=3;
		cost[2][3]=3;
		cost[3][4]=4;
		cost[4][3]=4;
		cost[4][8]=2;
		cost[8][4]=2;
		cost[4][7]=3;
		cost[7][4]=3;
		cost[8][7]=7;
		cost[7][8]=7;
		cost[7][6]=6;
		cost[6][7]=6;
		cost[6][5]=1;
		cost[5][6]=1;
		cost[5][2]=5;
		cost[2][5]=5;
		cost[5][13]=7;
		cost[13][5]=7;
		cost[6][12]=7;
		cost[12][6]=7;
		cost[6][11]=8;
		cost[11][6]=8;
		cost[7][10]=9;
		cost[10][7]=9;
		cost[8][9]=6;
		cost[9][8]=6;
		cost[9][10]=5;
		cost[10][9]=5;
		cost[10][3]=9;
		cost[3][10]=9;
		cost[11][12]=1;
		cost[12][11]=1;
		cost[12][13]=2;
		cost[13][12]=2;
	return chang;
}

void chaxun1(int cost[][maxs],int chang,int v1,int v2)
{
	int i,j,v,min;
	int s[maxs],d[maxs],p[maxs];
	for(i=1;i<chang;i++)
	{
		s[i]=0;
		d[i]=cost[v1][i];
		if(d[i]<maxs)
			p[i]=v1;
		else 
			p[i]=-1;
	}
	s[v1]=1;
	d[v1]=0;
	for(i=1;i<chang;i++)    
	{
		min=9999;
		for(j=1;j<chang;j++) 
		{
			if(s[j]==0&&d[j]<min)
			{
				v=j;         
				min=d[j];     
			}
		}
		s[v]=1;             
		for(j=1;j<chang;j++)     
		{
			if(s[j]==0&&d[v]+cost[v][j]<d[j])
			{
				d[j]=d[v]+cost[v][j];
				p[j]=v;
			}
		}
	}
	cout<<"从";
    show(v2);
	cout<<"到";
	show(v1);
	cout<<"最短路径为:"<<endl;
	if(s[v2]==1)
	{
		v=v2;
		while(v!=v1)
		{
			cout<<v;
			show(v);
			cout<<"-->";
			v=p[v];//通过找到前驱顶点，反向输出最短路径
		}
		cout<<v;
		show(v);
		cout<<"  路径长为"<<d[v2]<<endl;
	}
}

void print(){
	cout<<"                 欢迎使用黑龙江大学校园导游系统       "<<endl;
	cout<<"                    理工大学"<<endl;
	cout<<"    |-|-------------------------------------------------------"<<endl;
	cout<<"    | |               学府三道街"<<endl;
	cout<<"    |-|-------------------------------------------------------"<<endl;
	cout<<"  学|-①      ②体育馆         ⑤游泳馆             ①③音乐厅"<<endl;
	cout<<"    |-校                                                      "<<endl;
	cout<<"  府|         ③主             ⑥联通               ①②图书馆（旧）"<<endl;
	cout<<"    |-门        楼               广场               ①①实验楼"<<endl;
	cout<<"  路                                                          "<<endl;
	cout<<"    |-口                       ⑦校史馆（新图书馆） ⑩A区食堂"<<endl;
	cout<<"    |-|       ④A区            ⑧天天                        "<<endl;
	cout<<"    |-|         宿舍             广场               ⑨农学楼-"<<endl;
    cout<<"    |-|------------------------------------------------------"<<endl;
	cout<<"    |                 学府四道街"<<endl;
	cout<<"    |--------------------------------------------------------"<<endl;
	cout<<"    |                 医科大学"<<endl;
	cout<<"****************************************************************"<<endl;

}

void print2(){
	cout<<"请按任意键继续";
	getch();
}

void print1(){
	int flag=1;
	int a;
		while(flag){
		      cout<<"请输入想要了解的地点：";
		      cin>>a;
			 
			  switch(a){
			  case 1: system("cls");print();cout<<"学校的入口"<<endl;break;
			  case 2: system("cls");print();cout<<"搞体育的地方"<<endl;break;
			  case 3: system("cls");print();cout<<"行政区域"<<endl;break;
			  case 4: system("cls");print();cout<<"有妹子，有屌丝，还有...."<<endl;break;
			  case 5: system("cls");print();cout<<"除了水，还有........水"<<endl;break;
			  case 6: system("cls");print();cout<<"跑圈的地方"<<endl;break;
			  case 7: system("cls");print();cout<<"学校历史悠久，好啦，接下来...."<<endl;break;
			  case 8: system("cls");print();cout<<"恋爱圣地ps（冬天有点冷）"<<endl;break;
			  case 9: system("cls");print();cout<<"算是上自习的地方吧"<<endl;break;
			  case 10: system("cls");print();cout<<"还算比较好吃，二楼的过桥米线，三楼的麻辣烫....."<<endl;break;
			  case 11: system("cls");print();cout<<"做物理，电工实验的地方，去年死过人，胆小者勿入"<<endl;break;
			  case 12: system("cls");print();cout<<"书香"<<endl;break;
			  case 13: system("cls");print();cout<<"约会绝对必去的地方"<<endl;break;
			  }
			 cout<<"****************************************************************"<<endl;
		cout<<"按0回到主菜单，按任意键继续";
	    flag=getch()-48;
		cout<<endl;
	}
}

chaxun2(int cost[][maxs],int chang,int v1,int v2)
{
	int i,j,k;
	int d[maxs][maxs],p[maxs][maxs];
	for(i=1;i<chang;i++)
	{
		for(j=1;j<chang;j++)
		{
			d[i][j]=cost[i][j];
			if(d[i][j]<maxs)
				p[i][j]=i;
			else
				p[i][j]=-1;
			if(i==j)
				d[i][j]=0;
		}
	}
	for(k=1;k<chang;k++)
	{
		for(i=1;i<chang;i++)
		{
		    for(j=1;j<chang;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
	}
	cout<<"从";
    show(v1);
	cout<<"到";
	show(v2);
	cout<<"最短路径为:"<<endl;
	if(p[v1][v2]!=-1)
	{
		int s[maxs],t=-1,n=1;
		k=p[v1][v2];
		i=v1;
		j=v2;
		cout<<i;
		show(i);
		cout<<"-->";
		while(n==1||t!=-1)
		{
			if(n!=1)
			{
			
				i=j;
				j=s[t--];
				k=p[i][j];
				cout<<i;
				show(i);
				cout<<"-->";
			}
			n++;
			while(k!=i)
			{
				s[++t]=j;
				j=k;
				k=p[i][j];
				
			}
		}
		cout<<v2;
		show(v2);
	}		
	cout<<"  路径长为"<<d[v1][v2]<<endl;
}

main(){
	int v1,v2,m;
	int chang;
    int cost[maxs][maxs];
	int flag=1;
	int	flag1=1;
	int num,a;
	char ch;
	chang=chushihua(cost);
	/**/
   while(flag){
	   system("cls");
	   print();
	   cout<<"1景点介绍"<<endl;
	   cout<<"2从主楼出发到各景点最短路径查询"<<endl;
	   cout<<"3任意两点最短路径"<<endl;
	   cout<<"0退出"<<endl;
	   cin>>num;
	   switch(num){
	   case 1:print1();break;
	   case 2:cout<<"请输入要到达地点编号:";
	          cin>>v1;
			  system("cls");print();chaxun1(cost,chang,v1,1);print2();break;
	   case 3:cout<<"请输入您要查询的两个地点编号:";
	          cin>>v1>>v2;
			  system("cls");print();chaxun2(cost,chang,v1,v2);print2();break;
	   case 0:flag=0;
	   }
   }
}