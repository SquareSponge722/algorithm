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

const int NX = 1e5 + 7;
const int DX = 1e4 + 7;
int n;
int d[DX], maxd;
int pre[DX], nex[NX], first[DX];
bool down[NX];
ll ans = 0;

namespace BIT {
	int nd[NX];
	inline void add(int x, int k) {
		for(rg i = x; i <= n; i += i&-i)
			nd[i] += k;
	}
	inline int get(int x) {
		int res = 0;
		for(rg i = x; i > 0; i -= i&-i)
			res += nd[i];
		return res;
	}
}
using namespace BIT;

int main() {
	File("road");
	qrd(n);
	fr(i, 1, n) {
		qrd(d[i]); maxd = max(maxd, d[i]);
		if(!pre[d[i]]) first[d[i]] = i;
		nex[pre[d[i]]] = i;
		pre[d[i]] = i;
	}
	down[0] = down[n + 1] = 1;
	int last = 0;
	int l = 1, r = n;
	fr(i, 1, maxd) {
		if(first[i]) {
			ans += (i - last) * (get(r)- get(l - 1) + 1);
			last = i;
			int tmp = first[i];
			down[tmp] = 1;
			while(down[l]) l++;
			if(!down[tmp-1] && !down[tmp+1] && nex[tmp] != tmp + 1)
				add(tmp, 1);
			while(nex[tmp]) {
				tmp = nex[tmp];
				down[tmp] = 1;
				if(!down[tmp-1] && !down[tmp+1] && nex[tmp] != tmp + 1)
					add(tmp, 1);
			}
			while(down[r]) r--;
		}
	}
	printf("%d\n", ans);
	return 0;
}


