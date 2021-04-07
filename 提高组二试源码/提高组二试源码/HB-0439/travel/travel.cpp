#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<queue>
#include<cmath>
#define ll long long
#define inf 1e9
#define maxn 5005
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

vector <int> mp[maxn];
vector <int> ans;
int n,m,a[maxn];
bool vis[maxn];

inline void dfs(int u)
{
	ans.push_back(u);
	vector <int> tmp;
	tmp.clear(); vis[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(!vis[v]) tmp.push_back(v);
	}
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<tmp.size();i++)
	{
		int v=tmp[i];
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}
