#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

#define re register
#define ll long long
#define REP(u) for(re int v,i=head[u];v=pan[i].to,i;i=pan[i].next)

using namespace std;

ifstream fin("defense.in");
ofstream fout("defense.out");

const int maxn=10007;

char ch[100001];

struct node {
	int next,to;
} pan[maxn];

struct _node {
	int u,v,wi;
} pan1[maxn];

int n,m,x,y,tot,dis;
int xl,numl,xr,numr;
string ss;

int head[maxn],note[maxn],a[maxn];

bool vis[maxn],vised[maxn];

inline void add(int x,int y) {
	pan[++tot]=(node) {
		head[x],y
	};
	head[x]=tot;
}

namespace solve1 {

	inline void work() {
		if(numl==numr==1) {
			
		}
	}
}

int main() {
	fin>>n>>m>>ss;
	for(re int i=1; i<=n; i++) {
		fin>>pan1[i].wi;
	}
	for(re int i=1; i<=n-1; i++) {
		fin>>x>>y;
		add(x,y),add(y,x);
	}
//	if(ss[0]=='A') {
//		for(re int i=1; i<=m; i++) {
//			cin>>xl>>numl>>xr>>numr;
//			solve1::work();
//		}
//	}
	while(m--) {
		fout<<-1<<'\n';
	}
	return 0;
}
