#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n,m;
vector<int>q[5100];
inline void dfs(int x,int fa){
	int maxn=q[x].size();
	printf("%d ",x);
	for(int i=0;i<maxn;++i){
		int u=q[x][i];
		if(u==fa)continue;
		dfs(u,x);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		q[a].push_back(b);
		q[b].push_back(a);
	}
	for(int i=1;i<=n;++i){
		sort(q[i].begin(),q[i].end());
	}
	dfs(1,0);
	return 0;
}

