#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
//µã·Özhi 
const int mn =  50005;
const int inf = 5e8 + 10;
struct edge{
	int to,next,dis;
};
edge e[mn*2];
int head[mn],edge_max;
void add(int x,int y,int z)
{
	e[++edge_max].to=y;
	e[edge_max].dis=z;
	e[edge_max].next=head[x];
	head[x]=edge_max;
}
int n,m,f[mn],ans,sum,g[mn],tot;
void dp(int x,int ff)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==ff) continue;
		dp(v,x);
		ans = max(f[v]+e[i].dis+f[x],ans);
		f[x] = max(f[x],f[v]+e[i].dis);
	}
}
bool vis[mn];
int siz[mn],root,mx[mn],cnt;
void dfs(int x,int ff)
{
	siz[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==ff || vis[v]) continue;
		dfs(v,x);
		siz[x]+=siz[v];
		mx[x] = max(mx[x],siz[v]);
	}
	//cout<<"x = "<<x<<" "<<siz[x]<<endl;
	mx[x] = min(mx[x],sum-mx[x]);
	if(mx[x]>mx[root])
		root=x;
}
int ans2;
void getdeep(int x,int cost,int ff)
{
	ans2  = max(ans2,cost);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v] || v==ff) continue;
		getdeep(v,cost+e[i].dis,x);
	}
}
void solve(int x,int li)
{
	//cout<<x<<" "<<li<<endl;
	vis[x]=1;
	int trs=0;
	bool flag=false;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		//cout<<v<<endl;
		if(!vis[v])
		{
			tot=0;
			ans2=0;
			getdeep(v,e[i].dis,x);
			if(ans2+trs>=li)
				flag=true;
			trs = max(trs,ans2);
		}
	}
	if(flag) ans++;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v])
		{
			sum=siz[v];
			dfs(v,0);
			solve(v,li);
		}
	}
}
int kkss;
int st[mn],top;
bool check(int x)
{
	if(kkss==n)
	{
		top=0;
		for(int i=head[1];i;i=e[i].next)
		{
			int v=e[i].to;
			getdeep(v,x,e[i].dis);
			st[++top]=ans2;
		}
		ans=0;
		sort(st+1,st+1+top);
		for(int i=1;i<=top;i++)
			for(int j=1;j<i;j++)
				if(vis[i] && vis[j] && st[i]+st[j]>=x)
				{
					vis[i]=1,vis[j]=1;
					ans++;
				}
		return ans>=m;
	}
	ans=0;
	memset(vis,0,sizeof(vis));
	sum=n;
	dfs(1,0);
	solve(root,x);
	return ans>=m;
}
int main()
{
	int x,y,z;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
		if(x==1 || y==1)
			kkss++;
	}
	if(m==1)
	{
		dp(1,0);
		printf("%d",ans);
		return 0;
	}
	int l=0,r=inf,ret=0;
	while(r>=l)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			ret=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d",ret);
	return 0;
}



