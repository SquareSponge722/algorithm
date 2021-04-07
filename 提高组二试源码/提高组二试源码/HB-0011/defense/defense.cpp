#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<vector>

#define N 100001
#define M 500001
#define inf 0x3f3f3f3f

using namespace std;

int n, m, cnt, ans;
int w[N], head[N], ask[N], r[M];
string s;

struct node{
	int v, next;
	node() {}
	node(int v, int next): v(v), next(next) {}
}e[M];

void add(int u, int v) {
	e[++ cnt] = node(v, head[u]);
	head[u] = cnt;
} 

void init() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
}

void work(int u, int f) {
	for(int k = head[u]; k != -1; k = e[k].next) {
		r[k] = 1;
		if(k % 2)
			r[k + 1] = 1;
		else
			r[k - 1] = 1;
		if(!f) {
			int v = e[k].v;
			ans += w[v];
			for(int kk = head[v]; kk != -1; k = e[kk].next) {
				r[kk] = 1;
				if(k % 2)
					r[k + 1] = 1;
				else
					r[k - 1] = 1;
			}
		}
	}
}

int main() {
	//init();
	scanf("%d %d ", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i ++)
		scanf("%d", &w[i]);
	memset(head, -1, sizeof(head));
	memset(ask, -1, sizeof(ask));
	for(int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	while(m --) {
		int a, fa, b, fb;
		scanf("%d%d%d%d", &a, &fa, &b, &fb);
		if(!fa && !fb) {
			for(int k = head[a]; k != -1; k = e[k].next)
				if(e[k].v == b)	{
					printf("-1\n");
					break;
				}
		}
		else {
			ans = 0;
			for(int i = 1; i <= cnt; i ++)
				r[i] = 0;
			ask[a] = fa, ask[b] = fb;
			ans += w[a] * fa + w[b] * f[b];
			work(a, fa);
			work(b, fb);
		}
	}
	
	return 0;
	
}
