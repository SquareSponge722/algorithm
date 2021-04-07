#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
inline void read(int &x) {
	static char buf = getchar(); register int f = 1; x = 0;
	for (; !isdigit(buf); buf = getchar()) if (buf == '-') f = -1;
	for (;  isdigit(buf); buf = getchar()) x = x * 10 + buf - 48; x *= f;
}
//int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
set<int> book;
int n;
int tmp[10];
void init() {
	book.clear();
	read(n);
	for (int i = 1, x; i <= n; ++i) {
		read(x); book.insert(x);
	}
}
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T; read(T);
	while (T--) {
		init();
		for (set<int>::iterator it = book.begin(); it != book.end(); ++it)
			for (set<int>::iterator test = book.begin(); test != it; ++test)
				if ((*it) % (*test) == 0) {
					book.erase(it);
					break;
				}
		//for (set<int>::iterator it = book.begin(); it != book.end(); ++it) printf("%d ", *it); puts("");
		int tot = 0;
		for (set<int>::iterator it = book.begin(); it != book.end(); ++it) tmp[++tot] = *it;
		if (n <= 5) {
			if (tot == 5) {
				const int X = tmp[5]; bool flag = false;
				for (int A = 1; A <= (X >> 1); ++A) {
					int key = 0, B = X - A;
					for (int i = 1; i <= A / tmp[1]; ++i)
						if ((A - i * tmp[1]) % tmp[2] == 0) {
							++key; break;
						}
					for (int i = 1; i <= B / tmp[3]; ++i)
						if ((A - i * tmp[3]) % tmp[4] == 0) {
							++key; break;
						}
					if (key == 2) { flag = true; break; }
				} if (flag) book.erase(X);
			}
			if (tot == 4) {
				const int X = tmp[4]; bool flag = false;
				for (int A = 1; A <= (X >> 1); ++A) {
					int key = 0, B = X - A;
					for (int i = 1; i <= A / tmp[1]; ++i)
						if ((A - i * tmp[1]) % tmp[2] == 0) {
							++key; break;
						}
					if (B % tmp[3] == 0) ++key;
					if (key == 2) { flag = true; break; }
				} if (flag) book.erase(X);
			}
			if (tot == 3) {
				const int X = tmp[3]; bool flag = false;
				for (int A = 1; A <= (X >> 1); ++A) {
					int key = 0, B = X - A;
					for (int i = 1; i <= A / tmp[1]; ++i)
						if ((A - i * tmp[1]) % tmp[2] == 0) {
							++key; break;
						}
					if (key == 1) { flag = true; break; }
				} if (flag) book.erase(X);
			}
			printf("%d\n", book.size());
		}
		else {
			for (int i = tot; i >= 3; --i) {
				bool flag = false;
				for (int i = 1; i <= tmp[i] / tmp[1]; ++i)
					if (book.count(tmp[i] - i * tmp[1])) {
						book.erase(tmp[i]);
						flag = true;
						break;
					}
				if (flag) continue;
				for (int i = 1; i <= tmp[i] / tmp[2]; ++i)
					if (book.count(tmp[i] - i * tmp[2])) {
						book.erase(tmp[i]);
						flag = true;
						break;
					}
			}
			printf("%d\n", book.size());
		}
	}
	return 0;
}
