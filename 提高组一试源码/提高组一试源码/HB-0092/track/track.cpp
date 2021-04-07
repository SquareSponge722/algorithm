#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;

inline void read(int &x) {
	int w = 1;
	x = 0;
	char c = getchar();

	while(!isdigit(c)) {
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x*10 + c - '0';
		c = getchar();
	}
	x *= w;
}

struct Edge {
	int v,next,w;
} e[2*maxn];

int head[maxn],tot;
int vis[maxn];
int dis[maxn];
int in[maxn];
int s[maxn];
int num = 0;

void addnode(int x,int y,int z) {
	e[++tot].next = head[x];
	e[tot].v = y;
	e[tot].w = z;
	head[x] = tot;
}
int n,m,ans = -233;
void spfa(int x) {
	memset(vis,0,sizeof(vis));
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i] = INF;
	vis[x] = 1;
	dis[x] = 0;
	q.push(x);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=head[u]; i; i=e[i].next) {
			if(dis[e[i].v] > dis[u] + e[i].w) {
				dis[e[i].v] = dis[u] + e[i].w;
				if(!vis[e[i].v]) {
					vis[e[i].v] = 1;
					q.push(e[i].v);
				}
			}

		}
	}
}



int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n),read(m);
	int ok = 1;
	for(int i=1; i<n; i++) {
		int x,y,z;
		read(x),read(y),read(z);
		if(x == 1) ok = 0;
		addnode(x,y,z);
		addnode(y,x,z);
		in[x] ++;
		in[y] ++;
	}
	
	if(ok)
	{
		for(int i=head[1];i;i=e[i].next)
		{
			ans = max(e[i].w,ans);
		}
		printf("%d",ans);
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 1)
		{
			s[++num] = i;
		}
	}
	
	for(int i=1;i<=num;i++)
	{
	    spfa(s[i]);
		for(int j=1;j<=num;j++)
		{
			if(i!=j) ans = max(dis[s[j]],ans);
		}
	}
	printf("%d",ans);
	return 0;
}
