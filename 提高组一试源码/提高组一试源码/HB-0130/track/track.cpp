#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define N 1000010
using namespace std;
struct edge{
	int to,nxt,val;
	bool operator < (const edge &o) const
	{
		return val<o.val;
	}
}e[N];
int n,m,x,y,z,head[N],tot,ff[N],flag1,flag2,dis[N],t1,Max,ans,num[N],ef[N],vis[N];

void add(int x,int y,int z)
{
	e[++tot].to=y;
	e[tot].val=z;
	e[tot].nxt=head[x];
	head[x]=tot;	
}

void dfs1(int u,int fa)
{
	if(Max<dis[u])
	{
		Max=dis[u];
		t1=u;
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		int nex=e[i].to;
		if(nex==fa) continue;
		dis[nex]=dis[u]+e[i].val;
		dfs1(nex,u);	
	}	
}

void dfs2(int u,int fa)
{
	if(Max<dis[u])
	{
		Max=dis[u];
		ans=dis[u];
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		int nex=e[i].to;
		if(nex==fa) continue;
		dis[nex]=dis[u]+e[i].val;
		dfs2(nex,u);	
	}	
}

void dfs3(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int nex=e[i].to;
		if(nex==fa) continue;
		num[u]=e[i].val;
		dfs3(nex,u);	
	}	
}

bool check(int v)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+num[i];
		if(sum>=v)
		{
			cnt++;
			sum=0;
		}
	}
	if(cnt<m) return false;
	return true;
}

void work1()
{
	dfs1(1,0);
	Max=0;
	memset(dis,0,sizeof(dis));
	dfs2(t1,0);	
	printf("%d\n",ans);
}

void work2()
{
	dfs3(1,0);
	int l=1,r=500000002;
	while(l<=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
}

bool check2(int v)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(e[i].val>=v)
			cnt++;
		else 
		{
			int pos=lower_bound(ef+1,ef+tot+1,v-e[i].val)-ef;
			if(pos>=1 && pos<=tot)
			{
				vis[pos]=1;
				cnt++;
			}
		}
	}
	if(cnt>=m) return true;
	return false;
}

void work3()
{
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++) ef[i]=e[i].val;
	int l=1,r=500000002;
	while(l<=r)
	{
		memset(vis,0,sizeof(vis));
		int mid=(l+r+1)>>1;
		if(check2(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(y!=x+1) flag1=1;
		if(x!=1) flag2=1;
		add(x,y,z),add(y,x,z);
	}
	if(m==1) work1();
	else if(flag1==0) work2();
	else if(flag2==0) work3();
	return 0;
}

