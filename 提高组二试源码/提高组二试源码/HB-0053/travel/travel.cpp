#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#define N 5001
using namespace std;
int m,n,k;
struct node
{
	int a;
	int b;
}z[N];
int ans[N];
int h[N][N];
bool flag[N];
void dfs(int x,int dep)
{
	if(dep==n)
	{
		return ;
	}
	flag[x]=true;
	k=0;
	ans[dep]=x;
	for(int i=1;i<=m;i++)
	{
		
		if(z[i].a==x && flag[z[i].b]==false)
		{
			h[dep][k]=z[i].b;
			k++;
		}
		if(z[i].b==x && flag[z[i].a]==false)
		{
			h[dep][k]=z[i].a;
			k++;
		}
	}
	if(h[dep][0]==0)
	{
		return ;
	}
	sort(h[dep],h[dep]+k);
	for(int i=0;i<k;i++)
	{
		if(!flag[h[dep][i]])
		{
			flag[h[dep][i]]=true;
			dfs(h[dep][i],dep+1);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&z[i].a,&z[i].b);
	}
	flag[1]=true;
	ans[1]=1;
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
