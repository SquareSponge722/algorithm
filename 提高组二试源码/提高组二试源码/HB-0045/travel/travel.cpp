#include<bits/stdc++.h>
using namespace std;
int n,m,tot,head[5005],vis[5005],inq[5005];
queue<int>ans;
struct edge {
	int v,w,next;
} edge[10005];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void add(int u,int v,int w) {
	edge[++tot].v=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot;
}
inline void dfs(int u) {
	priority_queue< pair<int,int> >q;
	if(vis[u])return;
	vis[u]=1;
	ans.push(u);
	for(int i=head[u]; i; i=edge[i].next) {
		int v=edge[i].v,w=edge[i].w;
		q.push(make_pair(-w,v));
	}
	while(!q.empty()) {
		int nxt=q.top().second;
		q.pop();
		dfs(nxt);
	}
}
inline void bfs() {
	add(0,1,1);
	priority_queue< pair<int,int> >q;
	q.push(make_pair(-1,1));
	inq[1]=1;
	while(!q.empty()) {
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		inq[u]=0;
		ans.push(u);
		for(int i=head[u]; i; i=edge[i].next) {
			int v=edge[i].v,w=edge[i].w;
			if(!inq[v]) {
				inq[v]=1;
				q.push(make_pair(-w,v));
			}
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	if(m==n-1) {//没有环
		for(register int i=1; i<=m; i++) {
			int u=read(),v=read();
			add(u,v,v);
			add(v,u,u);
		}
		dfs(1);
		while(!ans.empty()) {
			printf("%d ",ans.front());
			ans.pop();
		}
	} else if(m==n) {//有环
		for(register int i=1; i<=m; i++) {
			int u=read(),v=read();
			add(u,v,v);
			add(v,u,u);
		}
		bfs();
		while(!ans.empty()) {
			printf("%d ",ans.front());
			ans.pop();
		}
	}
	return 0;
}
