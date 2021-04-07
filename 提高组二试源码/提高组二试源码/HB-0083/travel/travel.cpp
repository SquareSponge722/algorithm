#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 10000+10
#define M 5050
using namespace std;
int n,m;
int a[N],b[N],nt[N],p[N],flag[N],num,sum=1;
int q[N][N],t=1;
void add(int x,int y)
{
	++num;
	a[num]=x;
	b[num]=y;
	nt[num]=p[x];
	p[x]=num;
}
void dfs(int x)
{
	if(x==n)return ;
	memset(flag,0,sizeof(flag));
	flag[x]=1;
	int fr=0,tail=1;
	q[t][1]=x;
	while(fr<tail)
	{
		int k=q[t][++fr];
		int e=p[k];
		while(e>0)
		{
			int kk=b[e];
			if(!flag[kk])
			{
				sum++;
				q[t][++tail]=kk;
				flag[kk]=1;
				if(sum==n)
				{
					for(int j=1;j<=sum;j++)
					cout<<q[t][j]<<' ';
					return ;
				}
			}
			e=nt[e];
			flag[kk]=0;
		}
		t++;	
	}
	dfs(p[x]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1);
	/*
	int minv=1<<30;
	for(int i=1;i<=t;i++)
	if(minv>q[i][1])minv=q[i][1];
	for(int i=1;i<=n;i++)
	cout<<q[minv][i]<<' ';
	*/
	return 0;
}
