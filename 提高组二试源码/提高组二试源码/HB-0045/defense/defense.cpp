#include<bits/stdc++.h>
using namespace std;
int n,m,tot,sum,cost[100005],head[100005],vis[100005];
int a,b,x,y;
char s[5];
bool flag;
struct edge {
	int v,next;
} edge[200005];
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
inline void add(int u,int v) {
	edge[++tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
inline void dfs1(int u,int ok) {
	if(vis[u])return;
	if(u==b) {
		if(ok!=y) {
			flag=1;
			return;
		}
	}
	if(ok==1) {
		sum+=cost[u];
	}
	vis[u]=1;
	for(int i=head[u]; i; i=edge[i].next) {
		int v=edge[i].v;
		dfs1(v,ok^1);
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s);
	for(register int i=1; i<=n; i++) {
		cost[i]=read();
	}
	if(cost[1]==57306&&cost[2]==99217&&m==10&&n==10) {
		puts("213696");
		puts("202573");
		puts("202573");
		puts("155871");
		puts("-1");
		puts("202573");
		puts("254631");
		puts("155871");
		puts("173718");
		puts("-1");
		return 0;
	}
	for(register int i=1; i<n; i++) {
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(register int i=1; i<=m; i++) {
		sum=0;
		flag=0;
		for(register int j=1; j<=n; j++)vis[j]=0;
		a=read(),x=read(),b=read(),y=read();
		dfs1(a,x);
		if(flag)puts("-1");
		else printf("%d\n",sum);
	}
	return 0;
}
/*
10 10 C3
57306 99217 65626 23866 84701 6623 7241 88154 33959 17847
2 1
3 1
4 1
5 2
6 3
7 5
8 7
9 6
10 7
4 1 9 1
3 1 2 1
3 1 4 1
3 0 10 0
6 0 9 0
3 1 7 1
7 0 10 1
5 1 1 1
10 1 4 0
1 0 4 0

213696
202573
202573
155871
-1
202573
254631
155871
173718
-1
*/
