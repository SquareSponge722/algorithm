#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3fffffff;

int n, l, r, ans;
int d[MAXN];

inline int read ();
inline void Fill (int lft, int rgt, int up);

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	
	n = read ();
	for (int i = 1; i <= n; ++i){
		d[i] = read ();
	}
	
	Fill (1, n, 0);	
	
	printf ("%d", ans);
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}

inline int read ()
{
	char ch = getchar ();
	int f = 1;
	while (!isdigit (ch)){
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	int x = 0;
	while (isdigit (ch)){
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}

inline void Fill (int lft, int rgt, int up)
{
	if (lft == 0 || rgt == n + 1 || rgt == 0 || lft == n + 1){
//		cout << 'M' << endl;
		return ;	
	}
	
	while (d[lft] == up) ++lft;
	while (d[rgt] == up) --rgt;
	if (lft > rgt){
//		cout << 'M' << endl;
		return ;	
	}
	int minn = INF;
	int mid;
	for (int i = lft; i <= rgt; ++i){
		if (d[i] < minn){
			mid = i;
			minn = d[i];
		}
	}
	if (lft == rgt && minn - up <= 0) return;
//	if (lft == mid - 1 && rgt == mid + 1) return ;
	if (minn - up > 0) ans += (minn - up);
//	printf ("lft = %d, rgt = %d\n", lft, rgt);
//	printf ("up = %d, mid = %d, minn = %d, ans = %d\n", up, mid, minn, ans);
	Fill (mid + 1, rgt, minn);
	Fill (lft, mid - 1, minn);
}
