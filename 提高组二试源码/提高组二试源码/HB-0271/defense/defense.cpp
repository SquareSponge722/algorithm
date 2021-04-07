#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
const int mn = 100005;
struct edge{
	int to,next;
};
edge e[mn*2];
int head[mn],edge_max;
int val[mn],tag[mn];
int n,m,u[mn],v[mn],ans;
char opt[10];
void dfs(int x,int cost)
{
	if(cost>=ans) return ;
	if(x==n+1)
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(tag[u[i]]==0 && tag[v[i]]==0)
				flag=false;
		}
		if(flag)
		 	ans = min(ans,cost);
	/*	for(int i=1;i<=n;i++)
			cout<<tag[i]<<" ";
		cout<<endl;*/
		return ;
	}
	if(tag[x]!=-1)
	{
		if(tag[x]==1)
			dfs(x+1,cost+val[x]);
		else dfs(x+1,cost);
		return ;
	}
	if(tag[x]==-1)
	{
		tag[x]=1;
		dfs(x+1,cost+val[x]);
		tag[x]=0;
		dfs(x+1,cost);
		tag[x]=-1;
	}
}
int main()
{
	int x,y,a,b;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",opt);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		//add(x,y),add(y,x);
		u[i]=x,v[i]=y;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(tag,-1,sizeof(tag));
		tag[a]=x,tag[b]=y;
		ans = 0x3f3f3f3f;
		dfs(1,0);
		if(ans!=0x3f3f3f3f)
			printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
