#include <fstream>
#include <vector>
using namespace std;
ifstream in("travel.in");
ofstream out("travel.out");
bool u_v[5001][5001] = {false}, city[5001] = {false};
int n, m;
vector<int> vec;
inline void bfs(int);
int main()
{
	ios::sync_with_stdio(false);
	in >> n >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		in >> u >> v;
		city[i] = u_v[u][v] = u_v[v][u] = true;
	}
	for (int i = 1; i <= n; ++i)
		if (city[i])
			bfs(i);
	for (vector<int>::reverse_iterator b = vec.rbegin(), e = vec.rend(); b != e; ++b)
		out << *b << ' ';
	return 0;
}
inline void bfs(int i)
{
	for (int j = 1; j <= n; ++j)
		if (u_v[i][j] && city[j])
		{
			city[i] = u_v[i][j] = u_v[j][i] = false;
			bfs(j);
			vec.push_back(i);
			break;
		}
		else
			continue;
	return;
}
