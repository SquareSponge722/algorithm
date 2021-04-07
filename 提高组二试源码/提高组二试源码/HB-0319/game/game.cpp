#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1005;
const int mod = 1e9 + 7;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, m, num;
char tmp[N]; ll ans;
int mp[10][10], s[N][N], col[N];

int ANS[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 4, 8, 0},
	{0, 4, 12, 36, 0},
	{0, 8, 36, 112, 0},
	{0, 0, 0, 0, 0}
};

ll ksm(ll x, ll y)
{
	ll cnt = 1;
	while(y)
	{
		if(y % 2 == 1) cnt = cnt * x % mod;
		x = x * x % mod; y >>= 1;
	}
	return cnt;
}

struct node
{
	char w[N];
	friend bool operator < (node x, node y)
	{
		for(int i = 1; i <= n + m - 2; i++)
			if(x.w[i] != y.w[i]) return x.w[i] > y.w[i];
	}
}q[N];

void get_dr(int x, int y, char t[N], int deep)
{
	if(x == n && y == m)
	{
		num++;
		for(int i = 1; i <= deep; i++) q[num].w[i] = t[i];
		return;
	}
	if(x == n)
	{
		t[deep] = 'R'; get_dr(x, y + 1, t, deep + 1);
	}
	else if(y == m)
	{
		t[deep] = 'D'; get_dr(x + 1, y, t, deep + 1);
	}
	else
	{
		t[deep] = 'R'; get_dr(x, y + 1, t, deep + 1);
		t[deep] = 'D'; get_dr(x + 1, y, t, deep + 1);
	}
}

bool judge(int id)
{
	for(int i = 1; i <= n + m - 2; i++)
		if(s[id][i] < s[id - 1][i]) return false;
	return true;
}

void check()
{
	int p = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) mp[i][j] = col[++p];
	int x = 1, y = 1;
	for(int i = 1; i <= n + m - 2; i++)
	{
		if(q[1].w[i] == 'R') y++; else x++;
		s[1][i] = mp[x][y];
	}
	for(int i = 2; i <= num; i++)
	{
		x = y = 1;
		for(int j = 1; j <= n + m - 2; j++)
		{
			if(q[i].w[j] == 'R') y++; else x++;
			s[i][j] = mp[x][y];
		}
		if(!judge(i)) return;
	}
	ans++;
}

void dfs(int x)
{
	if(x > n * m)
	{
		check(); return;
	}
	col[x] = 1; dfs(x + 1);
	col[x] = 0; dfs(x + 1); 
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	n = read(); m = read();
	if(n <= 3 && m <= 3) cout << ANS[n][m];
	else if(n == 2)
	{
		ll ans = 4 * ksm(3, m - 1) % mod;
		cout << ans;
	}
	else
	{
		get_dr(1, 1, tmp, 1);
		sort(q + 1, q + 1 + num);
		dfs(1);
		cout << ans % mod;
	}
	return 0;
}
