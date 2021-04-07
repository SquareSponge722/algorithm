#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <iostream>
using namespace std;
inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
inline int scm(int a, int b) {
	return a * b / gcd(a, b);
}
inline int read() {
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

inline void Main();
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int TT = read();
	while (TT--) Main();
	return 0;
}

inline void Main() {
	register int n = read();
	set<int> s;
	list<int> lt;
	for (int i = 1; i <= n; i++) s.insert(read());
	for (register set<int>::iterator i = s.begin(); i != s.end(); i++) {
		for (register set<int>::iterator j = i; j != s.end(); j++) {
			if (i == j) continue;
			register int a = *i, b = *j, c;
			if (b % a == 0) {
				register int tmp = b;
				lt.push_back(tmp);
//				s.erase(*j);
				continue;
			}
			for (register int k = 1; (c = a * k) < b; k++) {
				if (s.count(b - c)) {
					register int tmp = b;
					lt.push_back(tmp);
					continue;
				}
			}
		}
	}
	for (register list<int>::iterator it = lt.begin(); it != lt.end(); it++) s.erase(*it);
	printf("%llu\n", s.size());
}
