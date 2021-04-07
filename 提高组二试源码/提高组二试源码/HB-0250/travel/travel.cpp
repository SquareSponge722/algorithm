#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 1000000

using namespace std;
//priority_queue<int, vector<int>, greater<int> >q;

int n,m;
int cnt,to[N],nxt[N],head[N];
void qxx(int x,int y)
{
	++cnt;
	nxt[cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
void add(int x,int y)
{
	qxx(x,y);
	qxx(y,x);
}

int back[N],visit[N],ff,fla[6000][6000];
int k[6000],ans[6000];
bool judge()
{
	for(int i=1;i<=n;i++)
	{
		if(k[i]==ans[i])continue;
		else if(k[i]<ans[i])return 1;
		return 0;
	}
	return 0;
}
void dfs(int x,int be)
{
	if(be==n+1){
		if(judge()||!ff){
			for(int i=1;i<=n;i++)ans[i]=k[i];
			ff=1;
		}
	}
	int minv=INT_MAX,mem,fl=0;
	for(int i=head[x];i!=0;i=nxt[i])
	{
		if(to[i]<minv&&visit[to[i]]==0&&fla[x][to[i]]==0){
			minv=to[i];
			mem=i;
			fl=1;
		}
	}
	if(fl){
		visit[minv]=1;
		fla[x][minv]=1;
		k[be]=minv;
		back[minv]=x;
		dfs(minv,be+1);
		visit[minv]=0;
	}
	if(minv!=INT_MAX&&fl)fla[x][minv]=0;
	if(x!=1)dfs(back[x],be);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	visit[1]=1;
	k[1]=1;
	dfs(1,2);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
