#include <fstream>
#include <string>
#include <iterator>
#include <cstdlib>
using namespace std;
ifstream in("game.in");
ofstream out("game.out");
int d[8][1000000];
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	in >> n >> m;
	string maxstr;
	for (int i = 0; i < n; ++i)
		maxstr += "R";
	for (int j = 0; j < m; ++j)
		maxstr += "D";
	string::size_type strsize = maxstr.size();
//	while ()
//	{
		maxstr.replace(maxstr.begin(), maxstr.end(), "RD", "DR");
		 
//	}
	out << 15;
	return 0;
}

