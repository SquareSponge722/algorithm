#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 100007
#define inf 0x7fffffff
using namespace std;
int n,m,cnt=0,front[maxn];
struct edge {
	int a,b,l;
} e[maxn];

inline void addedge(int u,int v,int w) {
	cnt++;
	e[cnt].a=front[u];
	e[cnt].b=v;
	e[cnt].l=w;
	front[u]=cnt;
}

inline int _min(int a,int b) {
	return a<b?a:b;
}

inline bool cmd(edge a,edge b) {
	return a.l<b.l;
}

inline int l_spfa() {
	int ans=-inf;
	queue<int> q;
	bool vis[maxn];
	int d[maxn];
	for(int i=1; i<n; i++)vis[i]=false,d[i]=-inf;
	for(int s=1; s<n; s++) {
		vis[s]=true;
		d[s]=0;
		q.push(s);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=front[u]; i; i=e[i].a) {
				int v=e[i].b,w=e[i].l;
				if(d[v]<d[u]+w) {
					d[v]=d[u]+w;
					if(!vis[v]) {
						vis[v]=true;
						q.push(v);
					}
				}
			}
		}
		int aa=-inf;
		for(int i=1; i<n; i++)if(aa<d[i])aa=d[i];
		if(aa>ans)ans=aa;
	}
	return ans;
}

bool flagA=true,flagB=true;
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		addedge(a,b,l);
		addedge(b,a,l);
		if(a!=1)flagA=false;
		if(b!=a+1)flagB=false;
	}
	if(m==1&&flagA) {
		sort(e+1,e+n,cmd);
		printf("%d",e[cnt].l+e[cnt-1].l);
	} else if(flagA&&(m!=1)) {
		sort(e+1,e+n,cmd);
		int minv=inf;
		for(int i=cnt,j=m; i>=m+(cnt-m)/2; i--,j++) {
			minv=_min(minv,e[i].l+e[j].l);
		}
		printf("%d",minv);
	} else if(flagB) {
		int ans=0;
		for(int i=1; i<=n-1; i++)ans+=e[i].l;
		printf("%d",ans);
	} else if(m==1&&(!flagA)) {
		printf("%d",l_spfa());
	}
	return 0;
}
