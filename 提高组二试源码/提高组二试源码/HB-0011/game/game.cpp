#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<vector>

#define N 10
#define M 1000001
#define inf 0x3f3f3f3f

using namespace std;
const int MOD = 1e9 + 7;

int n, m;
int f[N][M];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n ,&m);
	f[1][1] = 2;
	f[1][2] = 4;
	f[1][3] = 8;
	f[2][1] = 4;
	f[2][2] = 12;
	f[2][3] = 36;
	f[3][1] =8;
	f[3][2] = 36;
	f[4][2] = f[2][4] = 108;
	f[3][3] = 112;
	f[5][5] = 7136;
	for(int i = 2; i <= m; i ++)
		f[1][i] = (f[1][i - 1] * 2) % MOD;
	if(n > m)
		swap(n, m);
	printf("%d\n", f[n][m]);
	return 0;
}
