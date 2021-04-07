#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
const int maxn=50001;
using namespace std;
int m,n,mx;
int today,todayans;
int tot,to[maxn<<1],nxt[maxn<<1],head[maxn];
bool vis[maxn],len[maxn];
void Add(int u,int v,int w)
{
	to[tot++]=v,nxt[tot]=head[u],len[tot]=w,head[u]=tot;
}
void dis(int p)
{
	vis[p]=true;
}
void work1()
{
	mx=0;
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis(1);
	vis=0;
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dfs(mx);
	printf("%d",dis[mx]);
	exit(0);
}
book check(int mid)
{
	int now=0,nows=0;
	for(int i=1;i<n;i++)
	{
		nows+=le(i);
		if((nows)>=mid)
		now++,nows=0,i++;
	}
	return now>=m;
}
void work2()
{
	int ans=0,l=0,r=sum/2;
	while(l==r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		ans=mid;
		l=mid+1;
		else
		r=mid-1;
	}
	printf("%d",ans);
	exit(0);
}
bool check3(int mid)
{
	int now=0,nows=0;
	for(int i=2;i<=n;i++)
	dis[i-1]=len[head[i]];
	sort(dis+1,dis+n);
	int p1=1,p2=n-1;
	for(int i=1;i<m;i++)
	{
		if(dis[p2]>=mid)
		{
			p2--;
			continue;
		}
		while(dis[p1]+dis[p2]<mid&&p1<p2)
		p1++;
		if(p1==p2)
		return false;
		p1++,p2--;
	}
	return true;
}
void work3()
{
	int ans=0,l=0,r=sum/2;
	while(l==r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		ans=mid;
		l=mid+1;
		else
		r=mid-1;
	}
	printf("%d",ans);
	exit(0);
}
int TreeDP(int u)
{
	vis[u]=true;
	int cnt=0,tmp[son[u]+5];
	bool vi[son[u]+5];
	memset(tmp,0,sizeof(tmp));
	for(int i=head[u];i;i=nxt[i])
	{
		int vi=to[i];
		if(vis[vi])
		continue;
		tmp[cnt++]=TreeDP(vi)+len[i];
	}
	if(!cnt)
	return 0;
	sort(tmp+1,tmp+cnt+1);
	cout<<u<<endl;
	for(i=1;i<=cnt;i++)
	cout<<tmp<<endl;
	int p1=1,p2=cnt;
	while(tem[p2]>=today)
	todayans++,vi[p2]=true,p2--;
	while(p1<p2)
	{
		if(tem[p1]+tem[p2]<today)
		p1++;
		else
		todayans++,vi[p1]=vi[p2]=true,p1++,p2--;
	}
	for(int i=cnt;i>=1;i--)
	if(!vi[i])
	return tmp[i];
	return 0;
}
bool check(int mid)
{
	memset(vis,0,siazeof(vis));
	today=mid;
	todayans=0;
	TreeDP(1);
	return todayans>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);
		Add(v,u,w);
		if(v!=u+1)
		b2=false;
		if(u!=1)
		b3=false;
		sum+=w;
	}
	if(m==1)
	work1;
	else if(b2)
	work2();
	else if(b3)
	work3();
	int ans=0,l=0,r=sum/2;
	while(l==r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		ans=mid;
		l=mid+1;
		else
		r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
