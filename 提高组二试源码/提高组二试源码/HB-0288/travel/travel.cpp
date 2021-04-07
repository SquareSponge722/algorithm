#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;//60 DFS 40 BFS
const int MAXNODE=5005,MAXEDGE=30005;
int _map[MAXNODE][MAXNODE],_array[MAXEDGE];
int N,M,head,book[MAXNODE],tail;
void DFS(int now,int father)
{
	book[now]=1;
	head++;
	_array[head]=now;
	for(int i=1;i<=N;i++)
	{
		if(_map[now][i]&&i!=father&&!book[i])
		{
			DFS(i,now);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		_map[a][b]=1;
		_map[b][a]=1;
	}
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=N;j++)
//		{
//			printf("%d ",_map[i][j]);
//		}
//	}
	if(N==M+1)//DFS
	{
		DFS(1,0);
	}
	if(N==M)//BFS
	{
		tail++;
		_array[tail]=1;
		book[1]=1;
		while(head<tail)
		{
			head++;
			int now=_array[head];
			for(int i=1;i<=N;i++)
			{
				if(_map[now][i]&&!book[i])
				{
					tail++;
					book[i]=1;
					_array[tail]=i;
				}
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d ",_array[i]);
	}
	return 0;
}
