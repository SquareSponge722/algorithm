#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
const int N = 50005;
struct Edge
{
	int to,next,w;
}e[N];
int n,m,head[N],en(0),rudu[N]={0},wei[N];
long long ans=0;
bool vis[N]={0};

inline void AddEdge(int u,int v,int w)
{
	e[en].to=v;
	e[en].w=w;
	e[en].next=head[u];
	head[u]=en++;
}

void dfs(int x,long long s)
{
	if (rudu[x]==1 && s)
	{
		ans=max(s,ans);
		return;
	}
	for (int p=head[x];p!=-1;p=e[p].next)
	{
		int v=e[p].to;
		if (!vis[v])
		{
			vis[v]=1;
			dfs(v,s+e[p].w);
			vis[v]=0;
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rd(),m=rd();
	for (int i=0;i<N;i++) head[i]=-1;
	for (int i=1,x,y,z;i<n;i++)
	{
		x=rd(),y=rd(),z=rd();
		AddEdge(x,y,z);
		AddEdge(y,x,z);
		rudu[x]++;
		rudu[y]++;
		wei[x]=z;
		wei[y]=z;
	}
	int maxd,maxw=0;
	for (int i=1;i<=n;i++)
		if (rudu[i]==1)
		{
			if (wei[i]>maxw)
			{
				maxd=i;
				maxw=wei[i];
			}
		}
	vis[maxd]=1;
	dfs(maxd,0);
	cout<<ans<<endl;
	return 0;
}
