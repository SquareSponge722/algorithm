#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100006;
int n, m;
char ch[6];
ll p[N], f[N][2];
vector<int> e[N];

void chA() {
	while (m--) {
		int a, x, b, y;
		scanf("%d %d %d %d", &a, &x, &b, &y);
		memset(f, 0x3f, sizeof(f));
		f[a][x^1] = f[b][y^1] = -1;
		f[0][0] = f[0][1] = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i][0] != -1) f[i][0] = f[i-1][1];
			if (f[i][1] != -1) {
				if (f[i-1][0] == -1 && f[i-1][1] == -1) f[i][1] = -1;
				else if (f[i-1][0] == -1) f[i][1] = f[i-1][1] + p[i];
				else if (f[i-1][1] == -1) f[i][1] = f[i-1][0] + p[i];
				else f[i][1] = min(f[i-1][0], f[i-1][1]) + p[i];
			}
		}
		if (f[n][0] == -1 && f[n][1] == -1) {
			cout << "-1" << endl;
			continue;
		}
		if (f[n][0] == -1) {
			cout << f[n][1] << endl;
			continue;
		}
		if (f[n][1] == -1) {
			cout << f[n][0] << endl;
			continue;
		}
		cout << min(f[n][0], f[n][1]) << endl;
	}
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d %s", &n, &m, ch);
	for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if (ch[0] == 'A') {
		chA();
		return 0;
	}
	return 0;
}
