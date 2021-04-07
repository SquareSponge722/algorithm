#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int ge;
int ha[101];
int T;
int n;
int a[101];
int done[101];
int ans;
queue<int>q;
int bfs(int goal)
{
	//printf("%d:\n",goal);
	while(!q.empty())
	{
		q.pop();
	}
	for(int i=1;i<=ge;i++)
	{
		q.push(ha[i]);
	}
	while(!q.empty())
	{
		int now=q.front();
		//printf("%d ",now);
		q.pop();
		if(now==goal)
		{
			return 1;
		}
		if(now>goal)
		{
			continue;
		}
		for(int i=1;i<=ge;i++)
		{
			int ttt=now+ha[i];
			q.push(ttt);
		}
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		ge=0;
		memset(ha,0,sizeof(ha));
		memset(done,0,sizeof(done));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			if(done[i])
			{
				continue;
			}
			ans++;
			ge++;
			ha[ge]=a[i];
			for(int j=i+1;j<=n;j++)
			{
				int is=bfs(a[j]);
				if(is)
				{
					done[j]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
/*
3
16
27 29 15 28 26 8 18 21 10 22 30 20 16 25 23 7
16
27 29 15 28 26 8 18 21 10 22 30 20 16 25 23 7
16
27 29 15 28 26 8 18 21 10 22 30 20 16 25 23 7
*/
/*
7 8 10 15 16 18 20 21 22 23 25 26 27 28 29 30
1 1 1   0   0   0   0   0   0   0   0   0   0  0   0   0
*/