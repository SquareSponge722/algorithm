#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#define NO 1005
#define MAX 25100
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
//by Oliver
using namespace std;
ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while(ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while(ch >= '0' && ch <= '9')
		ans *= 10, ans += ch - '0', ch = getchar();
	if(ch == '-')
		return -ans;
	return ans;
}
//head

int T, n, a[NO], ans, Max;
bool book[MAX], book2[MAX];
//variable

void init()
{
	memset(book, false, sizeof(book));
	memset(a, 0, sizeof(a));
	Max = 0;
	ans = n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read(), Max = max(Max, a[i]);
	sort(a + 1, a + n + 1);
}
//functions

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	T = read();
	while(T--)
	{
		init();
		for(int i = 1; i <= n; i++)
		{
			if(book[a[i]])
				ans--;
			else
			{
				memset(book2, false, sizeof(book2));
				book[a[i]] = true;
				for(int j = 1; j <= Max; j++)
					if(book[j])
						book2[j % a[i]] = true;
					else if(book2[j % a[i]])
						book[j] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
//main
