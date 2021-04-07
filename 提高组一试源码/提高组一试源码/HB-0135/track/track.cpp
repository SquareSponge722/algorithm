#include <bits/stdc++.h>

using namespace std;

const int N = 50000 + 5;

int n, m;
int cnt, lim;

struct Edge {
	Edge *next;
	int w, v;	
	void *operator new(size_t, Edge *next, int v, int w) {
		static Edge pool[3*N], *p = pool;
		Edge *ret = p++;
		ret->next = next;
		ret->v = v;
		ret->w = w;
		return ret;
	}
} *head[N];

void add_edge(int u, int v, int w) {
	head[u] = new (head[u], v, w) Edge;
	head[v] = new (head[v], u, w) Edge;
}

int dfs(int u, int fa) {
	multiset<int> st;
	for (Edge *e = head[u]; e; e = e->next) {
		if (e->v != fa) {
			int fv = e->w + dfs(e->v, u);
			if (fv >= lim) {
				cnt++;
			} else {
				st.insert(fv);	
			}
		}
	}
	set<int> st2;
	while (!st.empty()) {
		multiset<int>::iterator it = st.begin();
		int cur = *it;
		st.erase(it);
		st2.insert(cur);
		multiset<int>::iterator it2 = st.lower_bound(lim - cur);
		if (it2 != st.end()) {
			cnt++;
			st2.erase(st2.find(cur));
			st.erase(it2);
		}
	}
	if (st2.empty()) {
		return 0;
	}
	set<int>::iterator it = st2.end();
	--it;
	return *it;
}

bool check(int mid) {
	lim = mid;
	cnt = 0;
	dfs(1, 0);
	return cnt >= m;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
	}
	int l = 0, r = 1e9;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%d\n", l);
	return 0;
}
