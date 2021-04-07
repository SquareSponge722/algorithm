#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int N = 100005;
using namespace std;
int n, a[N], num, cnt;
inline void init()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
int main()
{
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) if (!a[i]) num++;
	while (num != n)
	{
		int f = 0; int min_ = 999999; int start;
		for (int i = 1; i <= n; i++)
		{
			if (a[i])
			{
				if (!f) {f = 1; start = i;}
				min_ = min(min_, a[i]);
			}
			if (!a[i] || i == n)
				if (f)
				{
					f = 0;
					if (i == n && a[i]) i = n + 1;
					for (int j = start; j < i; j++)
					{
						a[j] -= min_;
						if (!a[j]) num++;
					}
					cnt += min_;
					min_ = 999999;
				}
		}
	}
	printf("%d", cnt);
	return 0;
}
