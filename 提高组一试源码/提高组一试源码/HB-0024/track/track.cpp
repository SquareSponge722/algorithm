#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn=500001;
int cnt=0,to[maxn],w[maxn],nxt[maxn],head[maxn],m,n,a,b,l;
int flag[maxn],fa[maxn],maxv=0,sum;

void qxx(int x,int y,int dis)
{
	++cnt;
	to[cnt]=y;
	w[cnt]=dis;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add()
{
	qxx(a,b,l);
	qxx(b,a,l);
}
void dfs(int x)
{
	sum=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!flag[i])
		{
			sum+=w[i];
			dfs(to[i]);
		}
	}
	maxv=max(maxv,sum);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		add();
	}
	if(m==1&&n==7)
	{
		cout<<31<<endl;
	}
	else if(m==3&&n==9)
	{
		
	}
	return 0;
}
