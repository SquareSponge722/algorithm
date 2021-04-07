#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>
#define rg register int
#define fr(i, A, B) for(rg i = A; i <= B; i++)
#define mes(arr, i) memset(arr, i, sizeof arr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;

template <class T>
inline void qrd(T &x) {
	x = 0; char ch; T y = 1;
	while(!isdigit(ch = getchar())) (ch == '-')&&(y = -1);
	while(isdigit(ch)) { x = (x*10) + (ch^48); ch = getchar(); }
	x *= y;
}

const int NX = 5007;
int n, m;
int u, v;
int out[NX];
int tar[NX][NX];
int fa[NX];
bool vis[NX], back[NX];
string ans, ord;

inline void dfs(int u, int fa) {
	printf("%d ", u);
	for(rg i = 1; i <= out[u]; i++) {
		int v = tar[u][i];
		if(v != fa) dfs(v, u);
	}
}

inline void emm(int u, int cnt) {
	string tmp = ord;
//	cout << ord << endl;
	if(ord > ans.substr(0, cnt * 2)) return;
//	cout << ans.substr(0, cnt * 2) << endl;
	if(cnt == n) {
		ans = min(ans, ord);
		return;
	}
	for(rg i = 1; i <= out[u]; i++) { 
		int v = tar[u][i];
		if(!vis[v]) {
			vis[v] = 1;
			fa[v] = u;
			ord += char(v + '0');
			ord += ' ';
			emm(v, cnt+1);
			vis[v] = 0;
			ord = tmp;
			fa[v] = 0;
		}
		else if(fa[u] == v && !back[v]){
			back[v] = 1;
			emm(v, cnt);
			back[v] = 0;
		}
	}
}

int main() {
	File("travel");
	qrd(n), qrd(m);
	fr(i, 1, m) {
		qrd(u), qrd(v);
		tar[u][++out[u]] = v;
		tar[v][++out[v]] = u;
	}
	fr(i, 1, n) sort(tar[i] + 1, tar[i] + out[i] + 1), ans += char('9'), ans += ' ';
	if(m == n-1) dfs(1, 0), puts("");
	else {
		ord += char('1');
		ord += ' ';
		vis[1] = 1; emm(1, 1);
		cout << ans << endl;
	}
	return 0;
}
