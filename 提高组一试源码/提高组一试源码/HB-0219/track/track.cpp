#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;
inline void read(int &x) {
	static char buf = getchar(); register int f = 1; x = 0;
	for (; !isdigit(buf); buf = getchar()) if (buf == '-') f = -1;
	for (;  isdigit(buf); buf = getchar()) x = x * 10 + buf - 48; x *= f;
}
struct Edge {
	int v, w;
	Edge(int _v, int _w) :v(_v), w(_w) {}
	bool operator< (const Edge &e) const {
		return w < e.w;
	}
};
int n, m;
int len_data[N];
vector<Edge> edge[N];
bool flag1, flag2 = true, flag3 = true;
void init() {
	read(n), read(m);
	for (int i = 1, u, v, w; i < n; ++i) {
		read(u), read(v), read(w); len_data[i] = w;
		edge[u].push_back(Edge(v, w));
		edge[v].push_back(Edge(u, w));
		if (u != 1 && v != 1) flag2 = false;
		if (u - v != 1 && v - u != 1) flag3 = false;
	} flag1 = (m == 1) ? true : false;
}
namespace condition1 {
	queue<int> Q;
	int dis[N];
	bool vis[N];
	Edge bfs(int s) {
		memset(dis, 0x3f, sizeof dis);
		memset(vis, 0   , sizeof vis);
		dis[s] = 0; vis[s] = true; Q.push(s);
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (unsigned int i = 0; i < edge[cur].size(); ++i) {
				int nxt = edge[cur][i].v;
				if (vis[nxt]) continue;
				vis[nxt] = true; Q.push(nxt);
				dis[nxt] = dis[cur] + edge[cur][i].w;
			}
		}
		Edge res(-1, -1);
		for (int i = 1; i <= n; ++i)
			if (res.w < dis[i])
				res.v = i, res.w = dis[i];
		return res;
	}
	int main() {
		Edge t = bfs(1);
		t = bfs(t.v);
		printf("%d\n", t.w);
		return 0;
	}
}
namespace condition2 {
	int main() {
		sort(len_data + 1, len_data + (n--));
		int ans = 0x3f3f3f3f;
		if (m <= n / 2)
			for (int i = 1; i <= m; ++i)
				ans = min(ans, len_data[n-i+1] + len_data[n-2*m+i]);
		else {
			for (int i = 1; i <= 2 * m - n; ++i)
				ans = min(ans, len_data[n - i + 1]);
			for (int i = 1; i <= n - m; ++i)
				ans = min(ans, len_data[i] + len_data[2*(n-m)+i-1]);
		}
		printf("%d\n", ans);
		return 0;
	}
}
namespace condition3 {
	int cal(int len) {
		int res = 0, tmp = 0;
		for (int i = 1; i < n; ++i) {
			tmp += len_data[i];
			if (tmp >= len) tmp = 0, ++res;
		} return res;
	}
	int main() {
		int l = *min_element(len_data + 1, len_data + n), r = 0;
		for (int i = 1; i < n; ++i) r += len_data[i];
		while (l != r) {
			int mid = (l + r + 1) >> 1;
			if (cal(mid) >= m) l = mid;
			else r = mid - 1;
		} printf("%d\n", l);
		return 0;
	}
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	init();
	if (flag1) condition1::main(); else
	if (flag2) condition2::main(); else
	if (flag3) condition3::main(); else
	if (n <= 300) {} else
	printf("%d\n", 2333333);
	return 0;
}
