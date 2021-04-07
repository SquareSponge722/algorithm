#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define N 10000000+100
using namespace std;
//priority_queue <int>q;
int n,m,flag[N],num,b[N],nt[N],p[N];
int a[N],t,ttt,sam=N,kkkk;
int d[1010][1010];
void add(int x,int y)
{
    num++;
    b[num]=y;
    nt[num]=p[x];
    p[x]=num;
};
int dfs(int x)
{
	flag[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(d[x][i]==1&&flag[i]==0)
		{
			a[++t]=i;//cout<<i<<endl;
			dfs(i);
		}
	}
	/*int e=p[x];
	while(e)
	{
	   int kk=b[e];
	   if(flag[kk]==0)
	   {
		      a[++t]=kk;
		      ttt=kk;dfs(kk);t--;
		}
	   e=nt[e];
	}
	if(ttt==x)
	{
	   //for(int i=1;i<=t;i++)cout<<a[i]<<endl;cout<<endl;
	   gb(++mn);
	}*/
}
void dfs1(int x)
{
	flag[x]=1;ttt=0;int gh=0;
	for(int i=1;i<=n;i++)
	{if(d[x][i]==1&&flag[i]==0&&kkkk==0)
		{
			ttt++;
		}
		if(ttt==2){sam=i;break;}
	}
	for(int i=1;i<=n;i++)
	{
		if(d[x][i]==1&&flag[i]==0&&sam>i)
		{
			a[++t]=i;gh=1;//cout<<i<<endl;
			dfs1(i);
		}
	}	
	if(gh==1&&kkkk==0)
	{
		a[++t]=sam;//cout<<i<<endl;
			dfs1(sam);
		sam=1000;
		kkkk=1;
	}
}
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			d[x][y]=1;
			d[y][x]=1;
		} a[++t]=1;
		dfs(1);for(int i=1;i<=t;i++)cout<<a[i]<<" ";
	}
	if(m==n)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			d[x][y]=1;
			d[y][x]=1;
		}a[++t]=1;
		dfs1(1);//cout<<sam<<endl;
		for(int i=1;i<=t;i++)cout<<a[i]<<" ";
	}
	return 0;
}
/*6 5
1 3
2 3
2 5
3 4
4 6*/
/*int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
	q.push(x);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<q.top();
		q.pop();
	}*/
