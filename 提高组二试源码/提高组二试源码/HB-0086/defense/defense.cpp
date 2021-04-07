//T2 defense
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int max_n = 100000;
int p[max_n];
vector <int> V[max_n];
int qread ();
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
	int u, v;	
	for (int i = 1; i < n; i++)
	{
		u = qread();
		v = qread();
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for (int i = 1; i <= m; i++)
	{
		int aa = qread(), xa = qread(), ba = qread(), ya = qread();
		cout << "GG = good game" << endl;
	}
	while (n--)
		cout << "ньньнь" << endl;
}
int qread()
{
	char c = getchar();
	int ans = 0;
	while (c > '9' || c < '0')
		c = getchar();
	while (c <= '9' && c >='0')
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}
