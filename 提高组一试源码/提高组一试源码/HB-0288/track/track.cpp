#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
#define run(a,b,c) for(a=b;a<=c;a++)
using namespace std;
int _map[3005][3005],ans,dis[3005][3004];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(dis,0,sizeof(dis));
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<N;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		_map[a][b]=c;
		_map[b][a]=c;
	}
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				dis[i][j]=max(_map[i][k]+_map[j][k],dis[i][j]);
				ans=max(ans,dis[i][j]);
			}
		}
	}
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=N;j++)
//		{
//			printf("%d %d %d \n",i,j,dis[i][j]);
//		}
//	}
	printf("%d",ans);
	return 0;
}
