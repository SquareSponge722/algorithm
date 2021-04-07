#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 105;
const int M = 25005;
int t;
int n;
int w[N];
int v[N];
int ans;
bool f[M];
inline void calc()
{
	for (int i = 2; i <= n; i ++)
	{
		for (int j = v[ans] + 1; j <= w[i]; j ++)
		{
			for (int k = 1; k <= ans; k ++)
				if(j - v[k])
					f[j] = f[j] || f[j - v[k]];
		}
		if(! f[w[i]])
		{
			v[++ ans] = w[i];
			f[w[i]] = true;
		}
	}
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	while(t --)
	{
		memset(w, 0, sizeof(w));
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
		ans = 0;
		int nn;
		scanf("%d", &nn);
		n = nn;
		for (int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			w[i] = x;
		}
		sort(&w[1], &w[n + 1]);
		v[++ ans] = w[1];
		f[v[ans]] = true;
		calc();
		printf("%d\n", ans);
	}
	return 0;
}
