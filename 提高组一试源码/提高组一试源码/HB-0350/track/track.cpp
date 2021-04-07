#include <bits/stdc++.h>
using namespace std;
const int N = 50006, L = 10006;
vector<pair<int, int> > e[N];
int n, m, a[N], len;
int s, maxs = 0, d[N];
int minl = L;
queue<int> q;
bool v[N];
int lian[N];

void bfs(int x) {
	while (q.size()) q.pop();
	q.push(x);
	memset(v, 0, sizeof(v));
	v[x] = 1;
	memset(d, 0, sizeof(d));
	while (q.size()) {
		int w = q.front();
		q.pop();
		for (unsigned int i = 0; i < e[w].size(); i++) {
			int y = e[w][i].first;
			if (v[y]) continue;
			v[y] = 1;
			int z = e[w][i].second;
			d[y] = d[w] + z;
			if (d[y] > maxs) {
				maxs = d[y];
				s = y;
			}
			q.push(y);
		}
	}
}

void m_1() {
	bfs(1);
	bfs(s);
	cout << d[s] << endl;
}

bool pd(int x) {
	int le = 1, ri = len;
	for (int i = 1; i <= m; i++) {
		if (le > ri) return 0;
		if (a[ri] >= x) {
			ri--;
			continue;
		}
		while (a[le] + a[ri] < x && le < ri) le++;
		if (le >= ri) return 0;
		le++;
		ri--;
	}
	return 1;
}

void a_1() {
	len = e[1].size();
	for (int i = 0; i < len; i++) a[i+1] = e[1][i].second;
	sort(a + 1, a + len + 1);
	int le = 0, ri = a[len] + a[len-1];
	while (le < ri) {
		int mid = (le + ri) >> 1;
		if (pd(mid)) le = mid + 1;
		else ri = mid;
	}
	cout << le - 1 << endl;
}

void b_a() {
	for (int x = 1; x <= n; x++) {
		for (unsigned int j = 0; j < e[x].size(); j++) {
			int y = e[x][j].first, z = e[x][j].second;
			lian[min(x, y)] = z;
		}
	}
	int le = 0, ri = 20001;
	while (le < ri) {
		int mid = (le + ri) >> 1;
		int num = 0, p = 0;
		for (int i = 1; i < n; i++)
			if ((p += lian[i]) >= mid) {
				num++;
				p = 0;
			}
		if (num >= m) le = mid + 1;
		else ri = mid;
	}
	cout << le - 1 << endl;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	bool is_a_1 = 1, is_b_a = 1;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		e[a].push_back(make_pair(b, l));
		e[b].push_back(make_pair(a, l));
		minl = min(minl, l);
		if (a != 1) is_a_1 = 0;
		if (b != a + 1 && a != b + 1) is_b_a = 0;
	}
	if (m == 1) {
		m_1();
		return 0;
	}
	if (m == n - 1) {
		cout << minl << endl;
		return 0;
	}
	if (is_a_1) {
		a_1();
		return 0;
	}
	if (is_b_a) {
		b_a();
		return 0;
	}
	return 0;
}
