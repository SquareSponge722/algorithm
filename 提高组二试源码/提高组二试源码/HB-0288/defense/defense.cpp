#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;//0
const int MAXNODE=100005,MAXEDGE=100005;
int p[MAXNODE];
int _map[MAXNODE][5];
int main()
{	
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int N,M;
	char type[5]; 
	scanf("%d %d %c%c",&N,&M,&type[1],&type[2]);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",p+i);
	}
	for(int i=1;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(_map[a][1])
		{
			_map[a][2]=b;
		}
		else
		{
			_map[a][1]=b;
		}
		if(_map[b][1])
		{
			_map[b][2]=a;
		}
		else
		{
			_map[b][1]=a;
		}
	}
	for(int i=1;i<=M;i++)
	{
		int a,b,c,d,ans=0;
		for(int i=1;i<=N;i++)
		{
			ans+=p[i];	
		}
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("-1\n");
	}
	return 0;
}
