#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX 0x7fffffff
#define MIN 0x80000000
#define ll long long
using namespace std;
inline void read(register int &x){
	x = 0; register int f = 1;
	register char ch = getchar();
	while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
const int N = 100 + 10;
const int M = 1000000 + 10;
int T, n, A[N], f[M], cnt, mx = MIN, ans[N];
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read(T);
	while (T--){
		read(n);
		mx = MIN, cnt = 0;
		for (register int i = 1; i <= n; i++) read(A[i]), mx = max(mx, A[i]);
		sort(A + 1, A + 1 + n);
		f[0] = 1;
		for (register int i = 1; i <= n; i++){
			if (f[A[i]] != 0) continue;
			cnt++;
			ans[cnt] = A[i];
			for (register int j = A[i]; j <= mx; j++){
				if (j >= A[i] && f[j] == 0) f[j] += f[j - A[i]];
			}
		}
		//for (register int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
		//putchar('\n');
		printf("%d\n", cnt);
		for (register int i = A[1]; i <= mx; i++) f[i] = 0;
	}
	return 0;
}
