#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

const int maxn = 1e5 + 10;

vector<pair<int, int> >G[maxn];

const int oo = int(1e9);

int Ans;
pair<int, int>f[maxn];
multiset<int>s;

typedef multiset<int>::iterator Iter;

void dfs(int u, int fa) {
	
	vector<int>tmp;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		if (v == fa) continue;
		dfs(v, u);
		f[u].first += f[v].first;
		int w = f[v].second + G[u][i].second;
		if (w >= Ans) f[u].first++;
		else tmp.push_back(w);
	}
	
	s.clear(); int n = tmp.size();
	for (int i = 0; i < n; i++) s.insert(tmp[i]);
	
	f[u].second = 0;
	
	while (s.size()) {
		int L = *s.begin();
		s.erase(s.find(L));
		int R = Ans - L;
		Iter it = s.lower_bound(R);
		if (it != s.end()) {
			f[u].first++;
			s.erase(it);
		} else {
			f[u].second = max(f[u].second, L);
		}
	}
}


int check(int n, int M) {
	Ans = M;
	memset(f, 0, sizeof f);
	dfs(1, -1);

	//for (int i = 1; i <= n; i++) 
	//	print(i);

	return f[1].first;
}
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int n = read(), m = read();
	int L = oo, R = 0;
	for (int i = 0; i < n - 1; i++) {
		int u = read(), v = read(), l = read();
		G[u].push_back(make_pair(v, l));
		G[v].push_back(make_pair(u, l));
		L = min(L, l); R += l;
	}
	
	R /= m;
	while (L < R) {
		int M = (L + R >> 1) + 1;
		if (check(n, M) >= m) L = M;
		else R = M - 1;
	}
	
	cout << L << endl;
}
