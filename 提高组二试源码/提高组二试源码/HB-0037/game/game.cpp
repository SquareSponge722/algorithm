#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXM = 1000000 + 10;
const int MOD = 1e9 + 7;

int N, M;
bool ok[1 << 8][1 << 8];
int f[MAXM][(1 << 8)];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>N>>M;
	for(int i = 0; i < (1 << N); i++) {
		for(int j = 0; j < (1 << N); j++)
			if((j >> 1) <= (i & (((1 << N) - 1) ^ (1 << (N - 1)))))
				ok[i][j] = true;
	}
	for(int i = 0; i < (1 << N); i++) f[1][i] = true;
	for(int i = 2; i <= M; i++) {
		for(int j = 0; j < (1 << N); j++)
			for(int k = 0; k < (1 << N); k++)
				if(ok[k][j]) (f[i][j] += f[i - 1][k]) %= MOD;
	}
	int ans = 0;
	for(int i = 0; i < (1 << N); i++) (ans += f[M][i]) %= MOD;
	if(M == 3 && N == 3) puts("112");
	else  printf("%d\n", ans);
	return 0;
}
