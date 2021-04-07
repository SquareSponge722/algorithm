#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define rg register int
#define fr(i, A, B) for(rg i = A; i <= B; i++)
#define mes(arr, i) memset(arr, i, sizeof arr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;

typedef long long ll;

template <class T>
inline void qrd(T &x) {
	x = 0; char ch; T y = 1;
	while(!isdigit(ch = getchar())) (ch == '-')&&(y = -1);
	while(isdigit(ch)) { x = (x*10) + (ch^48); ch = getchar(); }
	x *= y;
}

const int NX = 107;
const int MX = 25007;
int T, n;
int a[NX];
int mak[MX];

int main() {
	File("money");
	qrd(T);
	while(T--) {
		int maxa = 0;
		int ans = 0;
		qrd(n);
		fr(i, 1, n) {
			qrd(a[i]), maxa = max(maxa, a[i]);
			if(a[i] == 1) {
				puts("1");
				continue;
			}
		} 
		fr(i, 0, maxa) mak[i] = 0; mak[0] = 1;
//		sort(a + 1, a + n + 1);
		fr(i, 1, n) fr(j, a[i], maxa) {
			mak[j] += mak[j - a[i]];
		}
		fr(i, 1, n) if(mak[a[i]] == 1) ans++;
		printf("%d\n", ans);
	}
	return 0;
}

