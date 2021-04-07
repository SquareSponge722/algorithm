#include <fstream>
using namespace std;
ifstream in("road.in");
ofstream out("road.out");
int ans, d[100001], s[100001];
int main()
{
	int n;
	in >> n;
	for (int i = 1; i <= n; ++i)
	{
	 	in >> d[i];
		s[i] = d[i] - d[i - 1];
	}
	for (int i = 1; i <= n; ++i)
		if (s[i] > 0)
			ans += s[i];
	out << ans;
	return 0;
}
