#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
const int MAXA = 25000 + 10;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int T, N;
int a[MAXN], f[MAXA];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin>>T; 
	while(T--) {
		cin>>N;
		for(int i = 1; i <= N; i++) a[i] = read();
		memset(f, 0, sizeof(f)); f[0] = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = a[i]; j <= 25000; j++)
				f[j] += f[j - a[i]];
		}
		int ans = 0;
		for(int i = 1; i <= N; i++)
			ans += (f[a[i]] == 1);
		printf("%d\n", ans);
	} 
	return 0;
}
