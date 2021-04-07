#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, ans, d[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read();
	for(int i = 1; i <= n; i++)
	{
		d[i] = read();
		if(d[i] > d[i - 1]) ans += d[i] - d[i - 1];
	}
	cout << ans;
	return 0;
}
