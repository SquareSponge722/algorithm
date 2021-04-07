#include<bits/stdc++.h>
using namespace std;
int d[2005],ans,u,v,m,n,o,a,x,e,y;
bool f[2005],c[2005],b[2005][2005];
char k;
vector <int>path[100005];
void work1(int x);
void work2(int x);
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d %c%d",&n,&m,&k,&o);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		path[u].push_back(v);
		path[v].push_back(u);
		b[u][v]=b[v][u]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&x);
		scanf("%d%d",&e,&y);
		ans=0;
		if(b[a][e]==1&&x==0&&y==0)
		{
			printf("-1\n");
			continue;
		}
		if(x==1)
			c[a]=1,ans+=d[a];
		if(y==1)
		{
			c[e]=1,ans+=d[e];
			work1(e);
		}
		else if(x==1)
			work1(a);
		else if(x==0)
			work2(a);
		printf("%d\n",ans);
	}
	return 0;
}
void work1(int x)
{
	if(f[x])return;
	f[x]=1;
	ans+=d[x];
	int l=path[x].size();
	for(int i=0;i<l;i++)
	{
		u=path[x][i];
		if(c[u]==0&&f[u]==0)
		{
			work2(u);
		}
		else if(f[u]==1)
		continue;
	}
	return ;
}
void work2(int x)
{
	if(f[x])return;
	f[x]=1;
	int l=path[x].size();
	for(int i=0;i<l;i++)
	{
		u=path[x][i];
		if(c[u]==0&&f[u]==0)
		{
			
			c[u]=1;
			work1(u);
		}
		else if(f[u]==1)
			continue;
	}
	return ;
}
