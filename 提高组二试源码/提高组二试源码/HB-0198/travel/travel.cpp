#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#define MAXN 5005
using namespace std;

vector<int> g[MAXN];
int n,m;
int vis[MAXN],fa[MAXN],poi=0;
int ans[MAXN];
bool huan;

int read()
{
	char c=getchar();
	int r=0;
	while(c < '0' || c > '9') c=getchar();
	while(c >= '0' && c <= '9')
	{
		r=r*10+(c-'0');
		c=getchar();
	}
	return r;
}

void build()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int f,t;
		f=read(); t=read();
		g[f].push_back(t);
		g[t].push_back(f);
	}
	return;
}

void dfs(int s)
{
	ans[poi++]=s;
	vis[s]=1;
	sort(g[s].begin(),g[s].end());
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i] == fa[s]) continue;
		if(vis[g[s][i]])
		{
			if(huan) break;
			int poi2=poi-2,bigp=poi-2;
			while(ans[poi2] != g[s][i])
			{
				if(ans[poi2] > s) bigp=poi2;
				poi2--;
			}
			for(int j=bigp;j<=poi;j++)
			{
				vis[ans[j]]=0;
				fa[ans[j]]=0;
			}
			poi=bigp;
			fa[s]=g[s][i];
			huan=1;
			dfs(s);
			return;
		}
		fa[g[s][i]]=s;
		dfs(g[s][i]);
	}
	return;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	build();
	dfs(1);
	for(int i=0;i<poi;i++) cout<<ans[i]<<' ';
	return 0;
}
