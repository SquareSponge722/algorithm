#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[1005][1005]={0};
int ans[1000007]={0};
int n,t;
const int inf = 0x3f3f3f3f;
bool cmp(int x, int y)
{
	return x>y;
}


int main()
{
	//printf("%lld",sizeof(map)/1024/1024);
	freopen("track1.in","r",stdin);
	//freopen("track.out","w",stdout);

	scanf("%d%d",&n,&t);
	int maxN=n*n;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
		map[i][j] = inf;
	}
	for(int i=1;i<n;i++)
	{
		int ts,te,tv;
		scanf("%d%d%d",&ts,&te,&tv);
		map[ts][te] = tv;
		map[te][ts] = tv;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(map[i][j] > map[i][k] + map[j][k])
		{
			map[j][i] = map[i][j] = map[i][k] + map[j][k];
		}
	}
	for(int i=1;i<=n;i++)
	{
		map[i][i] = 0;
	}
	//vector<int> s
	int size=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		ans[size++] = map[i][j];
	}
	sort(ans+1,ans+n+1,cmp);
	printf("%d",ans[t]);
	return 0;
}

