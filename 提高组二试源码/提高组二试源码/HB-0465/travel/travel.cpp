#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#define maxn 5005

int arr[maxn],  head[maxn], vis[maxn], degr[maxn], vstd[maxn], others[maxn];
int otl=0;

struct edge {
	int v, next;
}edges[maxn<<1];
int n, m, tail, flag, otherside;
std::stack <int> stk;
void add_edge(int u, int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs(int u, int f) {
	if (vstd[u]) return;
	printf("%d ", u);
	vstd[u]=1;
	int tl=0;
	std::vector <int> L;
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v!=f&&vis[edges[i].v]==0) {tl++; L.push_back(edges[i].v);}
 	}std::sort(L.begin(), L.end());
 	for (int i=0;i<tl;++i) dfs(L[i], u);
}

void dfs3(int u) {
	if (vstd[u]) return;
	printf("%d ", u);
	vstd[u]=1;
	int tl=0;
	std::vector <int> L;
	for (int i=head[u];i;i=edges[i].next) {
		if (!vstd[edges[i].v]) {tl++;L.push_back(edges[i].v);}
	}std::sort(L.begin(), L.end());
	for (int i=0;i<tl;++i) {
		if (!vis[L[i]]) dfs(L[i], u);
		else {
			if (L[i]<otherside) dfs3(L[i]);
			else {
				otherside=n+1; return;}
		}
	}
}

void work_on_circle(int root) {
	vstd[root]=1; printf("%d ", root);
	flag=1; otherside=0;
	for (int i=head[root];i;i=edges[i].next) {
		if (!vstd[edges[i].v]) {
			others[++otl]=edges[i].v;
		}
	}std::sort(others+1, others+otl+1);
	for (int i=1;i<=otl;++i) {
		if (!vis[others[i]]) dfs(others[i], root);
		else {
			if (otherside==0) 
				for (int j=i+1;j<=otl;++j) if (vis[others[j]]) otherside=others[j];
			dfs3(others[i]);
		}
	}
}

void find_circle() {
	for (int i=1;i<=n;++i) {
		vis[i]=1;
		if (degr[i]==1) {
			vis[i]=0; stk.push(i);
		}
	}while (!stk.empty()) {
		int u=stk.top(); stk.pop();
		for (int i=head[u];i;i=edges[i].next) {
			degr[edges[i].v]--;
			if (degr[edges[i].v]==1) {
				vis[edges[i].v]=0;
				stk.push(edges[i].v);
			}
		}
	}
}

void dfs2(int u, int f) {
	if (vstd[u]) return;
	printf("%d ", u);
	vstd[u]=1;
	int tl=0;std::vector <int> L;
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v!=f) {++tl; L.push_back(edges[i].v);}
	}std::sort(L.begin(), L.end());
	for (int i=0;i<tl;++i) {
		if (!vis[L[i]]) dfs2(L[i], u);
		else work_on_circle(L[i]);
	}
}	





int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int u, v;
	tail=0;flag=0;std::memset(head, 0, sizeof(head));
	std::memset(degr, 0, sizeof(degr));
	std::memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	for (int i=1;i<=m;++i) {
		scanf("%d %d", &u, &v);
		add_edge(u, v); add_edge(v, u);
		degr[u]++; degr[v]++;
	}if (m==n-1) {
		dfs(1, 0);
		//for (int i=1;i<=n;++i) printf("%d ", vstd[i]);
	}
	else {
		std::memset(vstd, 0, sizeof(vstd));
		find_circle();
		dfs2(1, 0);
	}
	return 0;
}
