#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
const int maxm = 1e6 + 5;
const int P = 1e9 + 7;

int f[maxn][maxm][2], n, m;

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

inline int pls(int x, int y) {x += y; return x >= P ? x - P : x < 0 ? (x + P : x);}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	n = read(); m = read();
	
	f[1][1][1] = f[1][1][0] = 1;
	for(register int i = 1; i <= n; i++)
		for(register int j = 1; j <= m; j++)
			for(register int S = 0; S < 2; S++) {
				if(i < n && j < n) {
					f[i][j + 1][0] = pls(f[i][j + 1][0], f[i][j][S]);
					f[i + 1][j][1] = pls(f[i + 1][j][1], f[i][j][S]);
					f[i][j + 1][]  =
				} else if(i < n) {
					f[i + 1][j][0] = pls(f[i + 1][j][0], f[i][j][S]);
					f[i + 1][j][1] = pls(f[i + 1][j][1], f[i][j][S]);
				} else if(j < n) {
					f[i][j + 1][0] = pls(f[i][j + 1][0], f[i][j][S]);
					f[i][j + 1][1] = pls(f[i][j + 1][1], f[i][j][S]);
				}
			}
	
	return 0;
}
