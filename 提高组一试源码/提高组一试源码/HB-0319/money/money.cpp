#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 25005;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int T, n, mx, ans;
int a[N], v[N]; bool f[M];

void check()
{
	for(int j = v[v[0]]; j <= mx; j++) f[j] |= f[j - v[v[0]]];
}

void clear()
{
	memset(f, 0, sizeof(f)); f[0] = true;
	memset(v, 0, sizeof(v)); ans = 0;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	T = read();
	while(T--)
	{
		clear();
		n = read();
		for(int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + 1 + n); mx = a[n];
		for(int i = 1; i <= n; i++)
		{
			if(f[a[i]]) continue;
			v[++v[0]] = a[i]; ans++;
			check();
		}
		cout << ans << endl;
	}
	return 0;
}
