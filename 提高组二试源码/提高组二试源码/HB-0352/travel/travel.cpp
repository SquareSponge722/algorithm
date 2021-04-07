#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
const int N = 5005;
int n,m,g[N][N],g2[N][N],a[N],b[N],len=0;
bool vis[N]={0},ok=0;

void dfs(int u,int last)
{
	if (len==n)
	{
		return;
	}
		for (int v=1;v<=n;v++)
		{
			if (g[u][v])
			{
				if (!vis[v])
				{
					vis[v]=true;
					a[++len]=v;
					dfs(v,u);
					vis[v]=false;
				}
			}
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd(),m=rd();
	memset(g,0,sizeof g);
	for (int i=1,u,v;i<=m;i++)
	{
		u=rd(),v=rd();
		g[u][v]=1;
		g[v][u]=1;
	}
	a[++len]=1;
	vis[1]=1;
	dfs(1,0);


		for (int i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);


	
	return 0;
}
