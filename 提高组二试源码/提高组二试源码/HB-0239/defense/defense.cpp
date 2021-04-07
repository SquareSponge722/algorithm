#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct node_ {
	int v,next;
} node[200005];
int head[100005],e;
void addnode(int u,int v) {
	e++;
	node[e].v=v;
	node[e].next=head[u];
	head[u]=e;
}
int fa[100005];
int n,m;
string s;
int p[100005];
int d[100005][2];
void dfs1(int t) {
	for(int i=head[t]; i!=0; i=node[i].next) {
		if(node[i].v==fa[t])continue;
		fa[node[i].v]=t;
		dfs1(node[i].v);
	}
}
int a,x,b,y;
bool dfs(int t) {
	d[t][1]+=p[t];
	for(int i=head[t]; i!=0; i=node[i].next) {
		if(fa[t]==node[i].v) continue;
		if(x==0&&y==0&&(((node[i].v==b&&t==a)||(node[i].v==a&&t==b)))) return 0;
		if(!dfs(node[i].v)) return 0;
		d[t][0]+=d[node[i].v][1];
		d[t][1]+=min(d[node[i].v][1],d[node[i].v][0]);
	}
	if(a==t) {
		if(x==1) {
			d[t][0]=50000000;
		} else {
			d[t][1]=50000000;
		}
	} else if(b==t) {
		if(y==1) {
			d[t][0]=50000000;
		} else {
			d[t][1]=50000000;
		}
	}
	return 1;
}
int s1[100005],s2[100005];
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(register int i=1; i<=n; ++i) {
		scanf("%d",&p[i]);
	}
	for(register int i=1; i<n; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		addnode(u,v);
		addnode(v,u);
	}
	dfs1(1);
	for(register int ii=1; ii<=m; ++ii) {
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(d,0,sizeof(d));
		if(!dfs(1)) printf("-1\n");
		else printf("%d\n",min(d[1][1],d[1][0]));
	}
	return 0;
}
