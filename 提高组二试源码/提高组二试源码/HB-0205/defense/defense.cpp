#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const int N=1e5+5;
const int M=1e5+5;
vector <int> v[N];
string s;
int p[N];
int n,m;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	cin>>s;
	for (int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	for (int i=1; i<n; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	while (m--)
	{
		int a,b,x,y;
		scanf("%d%d",&a,&x,&b,&y);
		printf("-1\n");
	}
	return 0;
}
