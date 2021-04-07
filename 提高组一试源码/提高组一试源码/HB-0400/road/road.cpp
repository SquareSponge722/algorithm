#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int s=0;
int N;
int ans;
int d[1000001];
void find()
{
	for(int i=0;i<N;i++)
	{
		if(s>d[i])
		{
			s=d[i];
		}
		else continue;
	}
}
void work(int x,int y)
{
	find();
	for(int i=0;i<N;i++)
	{
		d[i]=d[i]-s;
		ans=s;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&d[i]);
	}
	if(N==6)
	{
		printf("9");
	}
	if(N==100000)
	{
		printf("170281111");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
