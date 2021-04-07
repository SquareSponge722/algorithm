#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

int n,m,ans,wa,flag[N];
int w[N],to[N],nxt[N],head[N],cnt;
void init(int x,int y,int z)
{
	++cnt;
	w[cnt]=z;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y,int z)
{
	init(x,y,z);
	init(y,x,z);
}
void dfs(int x)
{
	flag[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int t=to[i];
		if(!flag[t])
		{
			flag[t]=1;
			wa+=w[i];
			dfs(t);
			wa-=w[i];
			flag[t]=0;
		}
	}
	if(ans<wa)
		ans=wa;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	n--;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			flag[j]=0;
		dfs(i);
	}
	cout<<ans;
}

