#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 10;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct edge {
	int to, cost;
};vector<edge> g[MAXN];

int N, M;
int a[MAXN];

int tot = 0, val;
int dfs(int u, int fa) {
	multiset<int> son;
	for(int i = 0; i < (int) g[u].size(); i++) {
		edge &e = g[u][i];
		if(e.to == fa) continue;
		son.insert(dfs(e.to, u) + e.cost);
	}
	int res = 0;
	if(son.size() == 0) return 0;
	else {
		while(son.size() && *son.rbegin() >= val) {
			++tot; multiset<int>::iterator it = son.end(); 
			--it; son.erase(it);
		}
		
		while(son.size() > 1) {
			multiset<int>::iterator it = son.begin(), nt;
			int tmp = *it; res = *it; son.erase(it);
			nt = son.lower_bound(val - tmp);
			if(nt != son.end()) {
				++tot; son.erase(nt);
			}
		}	
		if(son.size()) return *son.begin();
	}
	return res;
}

inline bool check(int x) {
	val = x; tot = 0; dfs(1, 1);
	return tot >= M;
}

inline bool check1(int x) {
	int cnt = 0, tmp = 0;
	for(int i = 1; i < N; i++) {
		tmp += a[i]; 
		if(tmp >= x) ++cnt, tmp = 0;
	}
	return cnt >= M;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	cin>>N>>M;
	int l = 0, r = 0; bool flag = false;
	for(int i = 1; i < N; i++) {
		int u = read(), v = read(), c = read(); r += c;
		g[u].push_back((edge) {v, c}), g[v].push_back((edge) {u, c});
		flag |= (v != u + 1); 
		if(u > v) swap(u, v); a[u] = c;
	}
	
	if(!flag) {
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(check1(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
		return 0;
	}
	
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
