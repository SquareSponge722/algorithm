//travel
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#define MAXN 7050
using namespace std;
int n,m,cnt,cn,c;
struct edge
{
	int to;
	int ok;
	int nxt;
}a[MAXN<<1];
struct node
{
	int u;int v;int bo;
	bool operator < (const node& x)const{
		return v>x.v;
	}
}e[MAXN<<1];
int book[MAXN],h[MAXN],fan[MAXN],cut[MAXN],flag,blade[MAXN],dfn[MAXN],cur[MAXN];

void add(int u,int v,int bo)
{
	a[++cnt].to=v;
	a[cnt].ok=bo;
	a[cnt].nxt=h[u];
	h[u]=cnt;
}

int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum;
}

void dfs(int u,int f)
{
	int y;
	fan[++cn]=u;
	for(int i=h[u];i;i=a[i].nxt)
	{
		y=a[i].to;
		if(y!=f)
		{
			dfs(y,u);
		}
	}
}

void dfs1(int u,int f)
{
	int y;
	blade[++cn]=u;
	for(int i=h[u];i;i=a[i].nxt)
	{
		y=a[i].to;
		if(!cut[a[i].ok]&&y!=f)
		{
			if(y>fan[cn+1]&&flag!=-1)
			{
				flag=0;
				return;
			}
			else if(y<fan[cn+1])flag=-1;
			dfs1(y,u);
			if(flag==0)return;
		}
	}
}

void dfs2(int u,int f)
{
	int y;
	dfn[u]=dfn[f]+1;
	for(int i=h[u];i;i=a[i].nxt)
	{
		y=a[i].to;
		if(y!=f)
		{
			if(dfn[y])
			{
				dfn[u]=dfn[y];
				cur[++c]=a[i].ok;
				return;
			}
			dfs2(y,u);
			if(dfn[y]<=dfn[u])
			{
				dfn[u]=dfn[y];
				cur[++c]=a[i].ok;
				return;
			}
		}
	}
}

void work1()
{
	dfs(1,0);
}

void work2()
{
	dfs2(1,0);
	for(int i=1;i<=c;++i)
	{
		cut[cur[i]]=1;
		flag=1,cn=0;
		dfs1(1,0);
		if(flag)
		for(int j=1;j<=n;++j)fan[j]=blade[j];
		cut[cur[i]]=0;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	int u,v;
	for(int i=1;i<=m;++i)
	{
		e[i].u=read(),e[i].v=read();
		e[i+m].u=e[i].v,e[i+m].v=e[i].u;
		e[i].bo=e[i+m].bo=i;
	}
	sort(e+1,e+(m<<1)+1);
	for(int i=1;i<=(m<<1);++i)add(e[i].u,e[i].v,e[i].bo);
	memset(fan,0x3f,sizeof(fan));
	if(m==n-1)work1();
	else work2();
	for(int i=1;i<=n;++i)
	cout<<fan[i]<<" ";
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6

*/
