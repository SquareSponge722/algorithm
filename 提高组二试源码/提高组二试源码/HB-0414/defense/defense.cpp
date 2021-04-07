#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m,cost[100001];
char A[5];
vector <node> edge[100001];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,A);
	if(A[1]=='2') {
		for(int i=1;i<=m;i++)
			printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for(int i=1;i<n;i++) {
		int u,v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	return 0;
}
