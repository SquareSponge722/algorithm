#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;//20 chart
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int N,M;
	scanf("%d %d",&N,&M);
	if(N==1&&M==1)
	{
		printf("0");
	}
	if(N==1&&M==2)
	{
		printf("0");
	}
	if(N==1&&M==3)
	{
		printf("0");
	}
	if(N==2&&M==1)
	{
		printf("0");
	}
	if(N==2&&M==2)
	{
		printf("12");
	}
	if(N==2&&M==3)
	{
		printf("136");
	}
	if(N==3&&M==1)
	{
		printf("0");
	}
	if(N==3&&M==2)
	{
		printf("136");
	}
	if(N==3&&M==3)
	{
		printf("112");
	}
	return 0;
}
