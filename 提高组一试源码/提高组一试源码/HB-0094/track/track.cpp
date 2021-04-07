#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define MAXN 50500
using namespace std;
int n,cnt,m,cd,tot;
struct edge
{
	int to;
	int power;
	int nxt;
}a[MAXN<<1];
int h[MAXN],b[MAXN<<1],c[MAXN],son[MAXN];

int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum;
}

void add(int u,int v,int w)
{
	a[++cnt].to=v;
	a[cnt].power=w;
	a[cnt].nxt=h[u];
	h[u]=cnt;
}

void work1()
{
	int cn=0;
	for(int i=1;i<cnt;i+=2)
	{
		b[++cn]=a[i].power;
	}
	sort(b+1,b+cn+1,greater<int>());
	for(int i=1;i<=m;++i)
	c[i]=b[i]+b[(m<<1|1)-i];
	sort(c+1,c+m+1,greater<int>());
	cout<<c[m];
	return;
}

int dfs1(int u,int f)
{
	int y,dis,maxn=0;
	for(int i=h[u];i;i=a[i].nxt)
	{
		y=a[i].to;
		if(y!=f)
		{
			dis=dfs1(y,u);
			if(dis+a[i].power>maxn)
			{
				maxn=dis+a[i].power;
				son[u]=son[y];
			}
		}
	}
	if(!son[u])son[u]=u;
	return maxn;
}

void work2()
{
	int u;
	dfs1(1,0);
	u=son[1];
	cout<<dfs1(u,0);
	return;
}

void chuli(int u,int f)
{
	int y;
	for(int i=h[u];i;i=a[i].nxt)
	{
		if(y!=f)
		{
			b[++cd]=a[i].power;
			tot+=b[cd];
			chuli(y,u);
		}
	}
}

bool check(int mid)
{
	int ss=0,sumv=0;
	for(int i=1;i<=cd;++i)
	{
		if(ss<mid)ss+=b[i];
		if(ss>=mid)
		{
			ss=0;
			sumv++;
		}
		if(sumv==m)return true;
	}
	return false;
}

void work3()
{
	chuli(1,0);
	int left=1,right=tot,mid;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(check(mid))
		left=mid+1;
		else right=mid-1;
	}
	cout<<right;
	return;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	int u,v,w;
	bool flag=true;
	for(int i=1;i<n;++i)
	{
		u=read(),v=read(),w=read();
		if(u!=1)flag=false;
		add(u,v,w);
		add(v,u,w);
	}
	if(flag)
	{
		work1();
		return 0;
	}
	else if(m==1)
	{
		work2();
		return 0;
	}
	else work3();
	return 0;
}
/*
12 1
1 2
1
1 3 3
1 4 2
2 5 1
2 6 4
3 7 4
3 8 3
4 9 7
4 10 2
6 11 1
6 12 1

16

*/
