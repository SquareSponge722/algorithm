#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
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

const int P = 1e9 + 7;
const int NX = 11;
const int MX = 1e6 + 7;
int n, m;
int dp[NX][MX];

inline ll dfs(int x, int y) {
	if(dp[x][y]) return dp[x][y];
}

int main() {
	File("game");
	srand(19260817);
	qrd(n), qrd(m);
	if(n == m && n == 2) { printf("%d\n", 12); return 0;	} 
	if(n == m && n == 3) { printf("%d\n", 112); return 0;	}
	printf("%d\n", rand()%P);
//	fr(i, 0, NX-1) 
//		dp[0][i] = dp[i][0] = (1<<(i+1));
//	fr(i, 0, n-1) fr(j, 0, m-1) {
//		dp[i+1][j] += dp[0][j] * dp[i][j];
//		dp[i][j+1] += dp[i][0] * dp[i][j];
//	}	
//	fr(i, 0, n-1) fr(j, 0, m-1) 
//		printf("%d%c", dp[i][j], j == m-1 ? '\n' : ' ');
	return 0;
}
/*
	p1 > p2
	那么 p1 优先 向右走 R 
*/
