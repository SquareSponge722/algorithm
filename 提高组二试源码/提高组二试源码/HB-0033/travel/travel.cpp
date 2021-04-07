#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector <int > city[5001];
bool vis[5001];
int d[5001];
int n,m;
int cnt=0;
void dfs(int step,int cur)
{
	d[++cnt]=cur;
	if(cnt==n) {
		for(int i=1; i<=n; ++i)
			printf("%d ",d[i]);
		printf("\n");
		exit(0);
	} 
	else {
		for(int i=0; i<city[cur].size(); ++i) {
			int nn=city[cur][i];
			if(!vis[nn]) {
				vis[nn]=true;
				dfs(step+1,nn);
				vis[nn]=false;
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		city[a].push_back(b);
		city[b].push_back(a);
	}
	for(int i=1; i<=n; ++i)
		sort(city[i].begin(),city[i].end());
	vis[1]=true;
	dfs(1,1);
	return 0;
}
