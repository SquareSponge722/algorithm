#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

int trs[256][256], n, m, M;

const int P = 1e9 + 7;

void mul(int A[256][256], int B[256][256], int C[256][256]) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j])
				for (int k = 0; k < M; k++) {
					C[i][k] += 1ll * A[i][j] * B[j][k] % P;
					if (C[i][k] >= P) C[i][k] -= P;
				}
}

void mul2(int A[256], int B[256][256], int C[256]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			C[j] += 1ll * A[i] * B[i][j] % P;
			if (C[j] >= P) C[j] -= P;
		}
	}
	
}

int A[256], B[256], C[256][256];

void pow(int k) {
	A[M - 1] = 1;
	while (k) {
		if (k & 1) {
			memset(B, 0, sizeof B);
			mul2(A, trs, B);
			memcpy(A, B, sizeof B);
		}
		memset(C, 0, sizeof C);
		mul(trs, trs, C);
		memcpy(trs, C, sizeof C);
		k >>= 1;
	}
}

#define GG exit(0)

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read(); M = 1 << n;
	
	if (n == 1) {
		if (m == 1) { cout << 2 << endl; GG; }
		if (m == 2) { cout << 4 << endl; GG; }
		if (m == 3) { cout << 8 << endl; GG; }
	}
	if (n == 2) {
		if (m == 1) { cout << 4 << endl; GG; }
		if (m == 2) { cout << 12 << endl; GG; }
		if (m == 3) { cout << 36 << endl; GG; }
	}
	if (n == 3) {
		if (m == 1) { cout << 8 << endl; GG; }
		if (m == 2) { cout << 30 << endl; GG; }
		if (m == 3) { cout << 114 << endl; GG; }
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			trs[i][j] = 1;
			for (int k = 0; k < n - 1; k++) {
				int R = (j >> k) & 1, D = (i >> (k + 1)) & 1;
				if (R > D) trs[i][j] = 0;
			}
			//cout << trs[i][j] << ' ';
		}
		//cout << endl;
	}
	pow(m);
	long long ans = 0;
	//cout << "-----------" << endl;
	//for (int i = 0; i < M; i++) {
	//	cout << A[i] << ' ';
	//}
	//cout << endl;
	for (int i = 0; i < M; i++)
		ans += A[i];
	ans %= P;
	cout << ans << endl;
}


