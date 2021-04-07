#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read() {
	register int  x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	return 0;
}

