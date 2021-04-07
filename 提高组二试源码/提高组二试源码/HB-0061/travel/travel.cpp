#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdlib>
#include<iostream>
using namespace std;
const int N=5005;
int n,m,tot,k,x,y,ans[N],b[N],v[N];
bool use[N];
vector <int> f[N],g[N];
bool flag;
inline int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		w=-1;
		ch=getchar();	
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}

void dfss(int x,int step)
{
	if(step==2*n)
	{
		return ;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int xx=g[x][i];
		if(use[xx])
			continue;
		use[xx]=1;
		ans[++tot]=xx;
		dfss(xx,step+1);
		use[xx]=0;
	}
}
void dfst(int x,int step)
{
	if(step==2*n-1)
	{
		return ;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int xx=g[x][i];
		if(use[xx])
			continue;
		use[xx]=1;
		ans[++tot]=xx;
		dfst(xx,step+1);
		use[xx]=0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();y=read();
		f[x].push_back(y);
		f[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=0;j<f[i].size();j++)
		{
			b[++k]=f[i][j];
		}
		sort(b+1,b+k+1);
		for(int j=1;j<=k;j++)
		{
			g[i].push_back(b[j]);
		}
	}
	if(m==n-1)
	{
		ans[++tot]=1;
		use[1]=1;
		dfss(1,1);
	}
	else
	{
		ans[++tot]=1;
		use[1]=1;
		dfst(1,1);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
/*
5 4
1 4
1 3
3 2
3 5
*/
