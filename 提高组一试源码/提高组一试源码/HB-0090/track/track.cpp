#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
struct node {
	int to, next, w;
} e[300009];
int x, y, z;
int head[30009];
long long ans[30009],dis[30009];
bool vis[30009];
void add(int x, int y, int z) {
	e[++tot].to=y;
	e[tot].w=z;
	e[tot].next=head[x];
	head[x]=tot;
}
queue<int>q;
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	long long sum=0;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	for(int i=1; i<=n; i++) {
		//	spfa(i);
		q.push(i);
		dis[i]=0;
		vis[i]=1;
		while(!q.empty()) {
			int fx=q.front();
			q.pop();
			vis[fx]=0;
			for(int i=head[fx]; i ; i=e[i].next) {
				int v=e[i].to;
				if(dis[v]<dis[fx]+e[i].w) {
					dis[v]=dis[fx]+e[i].w;
					if(!vis[v]) {
						q.push(v);
						vis[v]=1;
					}
					if(ans[i]<dis[v]) {
						ans[i]=dis[v];
					}
				}
			}
		}
	}
	for(int i=1; i<n; i++) {
		sum=max(sum, ans[i]);
	}
	printf("%lld",sum);
}
