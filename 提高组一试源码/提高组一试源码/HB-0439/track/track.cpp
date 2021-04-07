#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#define maxn 50005
#define inf 1e9
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

struct node{int to,w;};

vector <node> mp[maxn];
int e1[maxn],e2[maxn],e3[maxn],n,m,ans,dis1[maxn],dis2[maxn];
queue <int> que;
bool vis1[maxn],vis2[maxn];

inline bool jud(int x)
{
	int tmp=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=e3[i];
		if(tmp>=x) cnt++,tmp=0;
		if(cnt>=m) return true;
	}
	return false;
}

inline bool jud2(int x)
{
	int l=1,r=n-1,cnt=0;
	while(l<r)
	{
		if(e3[r]>=x) r--,cnt++;
		else
		{
			while(l<r&&e3[r]+e3[l]<x) l++;
			if(l==r) return false;
			else l++,r--,cnt++;
		}
		if(cnt>=m) return true;
	}
	return false;
}

inline void dfs1(int u)
{
	vis1[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		node v=mp[u][i];
		if(vis1[v.to]) continue;
		dis1[v.to]=dis1[u]+v.w;
		dfs1(v.to);
	}
}

inline void dfs2(int u)
{
	vis2[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		node v=mp[u][i];
		if(vis2[v.to]) continue;
		dis2[v.to]=dis2[u]+v.w;
		dfs2(v.to);
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	int flag1=1,flag2=1,mx=-1,mn=inf;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		mx+=w; mn=min(mn,w);
		if(u>v) swap(u,v);
		e1[i]=u; e2[i]=v; e3[i]=w;
		if(v!=u+1) flag1=0;
		if(u!=1) flag2=0;
		mp[u].push_back((node){v,w});
		mp[v].push_back((node){u,w});
	}
	if(flag1==1)
	{
		int l=mn,r=mx;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(jud(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(flag2==1)
	{
		sort(e3+1,e3+n);
		int l=mn,r=mx;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(jud2(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++) dis1[i]=0;
		dfs1(1);
		int flag=0,tmp=-inf;
		for(int i=1;i<=n;i++) if(dis1[i]>tmp) tmp=dis1[i],flag=i;
		dfs2(flag);
		for(int i=1;i<=n;i++) ans=max(ans,dis2[i]);
		cout<<ans<<endl;
		return 0;
	}
	else if(m==n-1)
	{
		cout<<mn<<endl;
		return 0;
	}
	return 0;
}
