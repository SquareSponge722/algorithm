#include <cstdio>
#include <cstdlib>
using namespace std;
bool ljzz[5010][5010];
bool vis[5010];
int m,n;
int d[5010];
int las=5010;
int cs=1;
void init()
{
	for(int k=0;k<=n+1;k++)
		vis[k]=true;
	for(int k=0;k<=n+1;k++)
		for(int i=0;i<=n+1;i++)
		{
			ljzz[k][i]=false;
			ljzz[i][k]=false;
		}	
}
void dfs(int wz)
{
	if(cs==n)
	{
		for(int k=1;k<=n;k++)
			printf("%d ",d[k]);
		printf("\n");
		return ;
	}
	vis[wz]=true;
	for(int k=1;k<=n;k++)
	{
		if(!vis[k] && ljzz[wz][k])
		{
			d[++cs]=k;
			dfs(k);	
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	init();
	for(int k=1;k<=m;k++)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		ljzz[p][q]=true;
		ljzz[q][p]=true;
		vis[p]=false;
		vis[q]=false;
	}
	d[1]=1;
	dfs(1);
	return 0;
}
