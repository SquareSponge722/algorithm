#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
struct node
{
	int to,val;
}p;
vector<node> e[50001];
int vis[50001];
int ans;
int u[50001],v[50001],w[50001];
int n,m;
int dfs(int u,int q)
{
	int ed[1001],bk[1001];
	memset(ed,0,sizeof(ed));
	memset(bk,0,sizeof(bk));
	vis[u]=1;
	int cur=0;
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].to;
		if(vis[to]==0)
		{
			e[u][i].val+=dfs(to,q);
			ed[++cur]=e[u][i].val;
		}
	}
	sort(ed+1,ed+cur+1);
	for(int i=1;i<=cur;i++)
		if(ed[i]>=q)
			{
				ans++;
				bk[i]=1;
			}
	for(int i=1;i<=cur;i++)
		if(bk[i]==0)
		{
			int p=lower_bound(ed+i+1,ed+cur+1,q-ed[i])-ed;
			while(bk[p])
				p++;
			if(p>=cur+1)
				continue;
			bk[p]=1;
			bk[i]=1;
			ans++;
		}
	int res=0;
	for(int i=1;i<=cur;i++)
		if(!bk[i])
			res=max(res,ed[i]);
	return res;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	int l=0,r=999999999;
	while(l+1<r)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=1;i<=n;i++)
			e[i].clear();
		int mid=(l+r)/2;
		for(int i=1;i<=n-1;i++)
		{
			p.to=v[i],p.val=w[i];
			e[u[i]].push_back(p);
			p.to=u[i];
			e[v[i]].push_back(p);
		}
		dfs(1,mid);
		if(ans<m)
			r=mid;
		else
			l=mid;
	}
	printf("%d",r-1);
	return 0;
}
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/