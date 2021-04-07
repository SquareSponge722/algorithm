#include <cstdio>
#include <algorithm>
using namespace std;
bool con[5005][5005],book[5005];
int travel[5005],n,step,ans[5005],used[5005],f[5005],depth[5005],out[5005];
void dfstree(int u,int father)
{
	step++;
	travel[step]=u;
	if(step==n)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",travel[i]);
		return;
	}
	for(int i=1;i<=n;i++)
		if(i!=father && con[u][i]==1)
			dfstree(i,u);
	return;
}
/*void dfs(int u,int father)
{
	step++;
	travel[step]=u;
	if(step==n)
	{
		for(int i=1;i<=n;i++)
			if(ans[i]>travel[i])
			{
				for(int j=1;j<=n;j++)
					ans[j]=travel[j];
				break;
			}
		return;
	}
	for(int i=1;i<=n;i++)
		if(i!=father && con[u][i]==1)
			dfs(i,u);
	return;
}*/
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		con[a][b]=1;
		con[b][a]=1;
		out[a]++;
		out[b]++;
	}
	if(m==n-1)
		dfstree(1,1);
	else
	{
		int flag=1;
		for(int i=n;i>=1;i--)
		{
			if(out[i]>=2)
			{
				for(int j=1;j<=n;j++)
					if(con[i][j])
					{
						//printf("%d %d\n",i,j);
						con[i][j]=con[j][i]=0;
						flag=0;
						break;
					}
			}
			if(!flag)
				break;
		}
		//con[64][90]=con[90][64]=0;
		dfstree(1,1);
		/*
		for(int i=1;i<=n;i++)
			ans[i]=99999999;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(con[i][j]==1 && out[i]>=2 && out[j]>=2)
				{
					con[i][j]=0;
					con[j][i]=0;
					dfs(1,1);
					con[i][j]=1;
					con[j][i]=1;
				}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);*/
	}
	return 0;
}
