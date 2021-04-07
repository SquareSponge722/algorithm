#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>
#include <vector>
using namespace std;
ifstream in("money.in");
ofstream out("money.out");
bool is_s(int);
int main()
{
	int T;
	in >> T;
	for (int z = 1; z <= T; ++z)
	{
		int n, minx = 0x7fffffff, maxx = 0, p = 1, q = 1;
		int a[101] = {0}, is[101] = {0}, ns[101] = {0}, h[101] = {0};
		vector<int> v;
		in >> n;
		for (int i = 1; i <= n; ++i)
		{
			in >> a[i];
			maxx += a[i];
			if (minx > a[i])
				minx = a[i];
			if (is_s(a[i]))
				is[++p] = a[i];
			else
				ns[++q] = a[i];
		}
		sort(a + 1, a + n + 1);
		sort(is + 1, is + p + 1);
		sort(ns + 1, ns + q + 1);
		for (int i = 1; i <= n; ++i)
			h[i] = h[i - 1] + a[i];
		for (int i = 1; i <= maxx; ++i);
	}
	return 0;
}
inline bool is_s(int x)
{
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(x); i += 2)
		if (x % i == 0)
			return false;
	return true;
}
