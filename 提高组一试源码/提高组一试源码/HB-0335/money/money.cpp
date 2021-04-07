#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int Case,n,d[110],c[110],maxn=-1;
bool vis[25010];
inline void dfs(int x,int v) {
	if(x==c[0]+1) return ;
	for(int i=0;i*c[x]+v<=maxn;i++) {
		int t=i*c[x]+v;
		vis[t]=0; dfs(x+1,t);
	}
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&Case);
	while(Case--) {
		memset(vis,0,sizeof vis); maxn=-1; memset(c,0,sizeof c);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]), vis[d[i]]=1, maxn=max(maxn,d[i]);
		sort(d+1,d+1+n);
		c[++c[0]]=d[1]; int now=2;
		while(1) {
			dfs(1,0);
			int last=c[0];
			for(;now<=n;now++)
				if(vis[d[now]]) {
					c[++c[0]]=d[now];
					break ;
				} now++;
			if(last==c[0]) break ;	
		} 
		printf("%d\n",c[0]);
	}
	return 0;
}
