#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#define REP(u) for(int w,v,i=head[u];v=pan[i].to,w=pan[i].wi,i;i=pan[i].next)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,in),pa==pb)?EOF:*pa++

using namespace std;

FILE *in=fopen("1.in","r");

ofstream fout("track.out");
ifstream fin("track.in");

char buf[100000],*pa(buf),*pb(buf);

const int maxn=30007;

struct node {
	int next,to,wi;
} pan[maxn];

int head[maxn<<1];

int w[maxn],an[maxn],x[maxn];

int tot,n,ans,m,y,pass,num,sum,cnt;

bool vis[maxn];

inline int cmp(int x,int y){return x>y;}

inline int _max(int x,int y) {
	return x>y?x:y;
}

namespace solve1 {//m==1

	inline void dfs(int x) {
		REP(x) {
			if(!vis[v]) {
				vis[v]=1;
				pass+=w;
				ans=_max(ans,pass);
				dfs(v);
				pass-=w;
				vis[v]=0;
			}
		}
	}

	inline void work() {
		for(int i=1; i<=n; i++) {
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i);
			pass=0;
		}
	}
}

namespace solve2 {//ai=1
	inline void work() {
		sort(w+1,w+n+1,cmp);
		return;
	}
}

namespace solve3 {//bi=ai+1

	inline void work3();
	
	inline void dfs(int x) {
		REP(x) {
			if(!vis[v]) {
				vis[v]=true;
				an[++cnt]+=w;
				solve3::work3();
				dfs(v);
				an[--cnt]-=w;
				vis[v]=false;
			}
		}
	}

	inline void work3() {
		sort(x+1,x+n+1,cmp);
	}
}

inline void add(int x,int y,int z) {
	pan[++tot]=(node) {
		head[x],y,z
	};
	head[x]=tot;
}

int main() {
	fin>>n>>m;
	for(int i=1; i<=n-1; i++) {
		fin>>x[i]>>y>>w[i];
		if(y==x[i]+1) sum++;
		if(x[i]==1) num++;
		add(x[i],y,w[i]),add(y,x[i],w[i]);
	}
	if(m==1) {
		solve1::work(),fout<<ans<<' ';
		return 0;
	}
	if(num==n-1) {
		solve2::work();
		fout<<w[m];
	}
	if(sum==n-1) {
		solve3::work3();
	}
	return 0;
}
/*
5 3
1 2 3
2 3 4
3 4 5
4 5 6
*/
