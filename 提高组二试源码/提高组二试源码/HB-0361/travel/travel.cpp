#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define maxn 5007
using namespace std;

int read() {
	int s=1,x=0;
	char c=getchar();
	while(c<='0'||c>='9') {
		if(c=='-')s=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*s;
}
int cnt=0;
bool vis[maxn];
vector<int> g[maxn];
int n,m;

void dfs(int a) {
	int now;
	if((g[a].size()==1)&&(vis[g[a][0]]==false)) {
		printf("%d ",a);
		return;
	} else {
		vis[a]=false;
		printf("%d ",a);
		for(int i=0; i<g[a].size(); i++) {
			if(vis[g[a][i]]) {
				now=g[a][i];
				vis[now]=false;
				dfs(now);
			}
		}
		if((++cnt)==n) {
			vis[a]=true;
			return ;
		}
	}
}


int main() {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=m; i++) {
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; i++) {
		sort(g[i].begin(),g[i].end());
		vis[i]=true;
	
	}
	dfs(1);
	return 0;
}
