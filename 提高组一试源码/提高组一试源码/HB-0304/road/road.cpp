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
int n, ans, mn;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	read(mn);
	ans = mn;
	for (register int i = 2; i <= n; i++){
		register int a; read(a);
		if (a > mn) ans += a - mn;
		mn = a;
	}
	printf("%d\n", ans);
	return 0;
}
