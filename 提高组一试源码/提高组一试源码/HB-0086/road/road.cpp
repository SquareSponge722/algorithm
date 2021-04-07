//T1 road
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int qread();
int main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	unsigned long long ans = 0;
	int n;
	cin >> n;
	int p1 = 0, p2 = 0;
	while (n--)
	{
		p2 = qread();
		if (p2 > p1)
			ans += p2 - p1;
		p1 = p2;
	}
	cout << ans << endl;
	return 0;
}
int qread()
{
	char c = getchar();
	int ans = 0;
	while (c > '9' || c < '0')
		c = getchar();
	while (c <= '9' && c >= '0')
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}
