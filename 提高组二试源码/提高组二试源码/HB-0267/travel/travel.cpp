#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
bool a[5005][5005];
bool vis[5005];
int ans[50005],t[5005];
int n,m,tag,place,cur,cur2;
void DFS(int x)
{
	if(tag) return;
	if(place==n)
	{
		tag=1;
		return;
	}
	else
	{
		ans[place++]=x;
		for(int i=2;i<=n;i++)
		{
			if(!vis[i]&&a[x][i])
			{
				vis[i]=1;
				DFS(i);
				vis[i]=0;
			}
		}
	}
}
int fa[5005];
int find(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int p[5005],xx;
bool search(int x,int last)
{
	if(x==cur) return 1;
	for(int i=1;i<=n;i++)
	{
		if(i!=last)
		{
			if(a[x][i])
			if(search(i,x))
			{
				p[xx++]=i;
				return 1;
			}
		}
	}
	return 0;
}
bool pd()
{
	for(int i=0;i<n;i++) if(ans[i]!=t[i])
	{
		return ans[i] > t[i];
	}
	return false;
}
void DFS2(int x)
{
	t[place++]=x;
	if(place==n)
	{
		if(pd())
		{
			for(int i=0;i<n;i++) ans[i]=t[i];
		}
		return;
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i]&&a[x][i])
			{
				vis[i]=1;
				DFS2(i);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) ans[i]=1e9;
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=1;
		}
		vis[1]=1;
		place=0;
		DFS(1);
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=1;
			if(find(x)!=find(y)) fa[find(x)]=find(y);
			else
			{
				cur=x;
				cur2=y;
			}
		}
		a[cur2][cur]=a[cur][cur2]=0;
		search(cur2,cur);
		a[cur2][cur]=a[cur][cur2]=1;
		p[xx]=cur2;
		p[++xx]=cur;
		for(int i=0;i+1<=xx;i++)
		{
			memset(vis,0,sizeof vis);
			vis[1]=1;
			int u=p[i];
			int v=p[i+1];
			a[u][v]=a[v][u]=false;
			place=0;
			DFS2(1);
			a[u][v]=a[v][u]=true;
		}
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
