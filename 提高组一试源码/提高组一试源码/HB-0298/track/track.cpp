#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
	int x,v;
	node (int xx,int vv)
	{
		x=xx,v=vv;
	}
};
const int N=30005;
vector < node > g[N];
vector < node > bi[N];
int n,m,dp[N],ans,du[N],cnt,b[N],flag2=true,bb[N];
int dfs(int x,int fa,int sum)
{
	int len=g[x].size();
	for(int i=0;i<len;i++)
	{
		node t=g[x][i];
		if(t.x==fa)
			continue;
		sum+=t.v;
		dfs(t.x,x,sum);
		sum-=t.v;
	}
	ans=max(ans,sum);
	return ans;
}
bool check(int x)
{
	int sum=0,cn=0;
	for(int i=1;i<n;i++)
	{
		if(sum+bb[i]<=x)
			sum+=bb[i];
		else
			cn++,sum=bb[i];
	}
	if(cn<=m)
		return true;
	else
		return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	int minn=999999999,maxn=0;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		g[x].push_back(node(y,z));
		g[y].push_back(node(x,z));
		if(x==1)
			cnt++;
		if(y!=x+1)
			flag2=false;
		du[x]++;
		du[y]++;
		b[i]=z;
		minn=min(minn,z);
		maxn+=z;
		bi[x].push_back(node(y,z));
	}
	if(m==1)
	{
		if(cnt==n-1)
		{
			sort(b+1,b+n);
			printf("%d",b[n-1]+b[n-2]);
			return 0;
		}
		int root;
		for(int i=1;i<=n;i++)
			if(du[i]==1)
				root=i;
		printf("%d",dfs(root,0,0));
		return 0;
	}
	if(flag2==true)
	{
		for(int i=1;i<n;i++)
			bb[i]+=g[i][0].v;
		int l=minn,r=maxn;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",l);
		return 0;
	}
}
