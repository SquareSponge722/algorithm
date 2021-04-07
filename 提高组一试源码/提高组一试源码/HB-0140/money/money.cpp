#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int T, n, a[maxn], vis[maxn], ans, b[maxn], tot, mn, judge;

bool f[maxn * maxn * maxn * 20];
vector<pair<int, int> > p;

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

inline void init() {
	tot = 0; mn = inf; ans = 0; judge = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(f, 0, sizeof(f));
	memset(vis, 0, sizeof(vis));
	p.clear();
}

inline bool check(int p) {
	for(register int i = p; i <= tot && b[i] < mn; i++)
		if(!f[b[i]]) return false;
	return true;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	T = read();
	while(T--) {
		init();
		n = read(); 
		for(register int i = 1; i <= n; i++) a[i] = read();
		
		sort(a + 1, a + 1 + n);
		
		for(register int i = 1; i <= n; i++) if(!vis[i]) {
			for(register int j = i + 1; j <= n; j++)
				if(a[j] % a[i] == 0) vis[j] = 1;
			b[++tot] = a[i]; judge |= (a[i] == 2);
		}
		
		if(a[1] == 1 || n == 1 || tot == 1) {cout << 1 << endl; continue;}
		if(judge) {cout << 2 << endl; continue;}
		
		for(register int i = 1; i <= tot; i++)
			for(register int j = i + 1; j <= tot; j++)
				mn = min(mn, (b[i] - 1) * (b[j] - 1));
		
		/*for(register int i = 1; i <= tot; i++)
			cerr << b[i] << " ";
		cerr << '\n' << mn << '\n';*/
		
		f[0] = 1;
		for(register int i = 1; i <= tot; i++) {
			ans += !f[b[i]];
			for(register int j = b[i]; j < mn; j++) f[j] |= f[j - b[i]];
			if(check(i + 1)) {cout << ans << endl; break;}
		}
		//cerr << "ok" << endl;
	}
	return 0;
}
