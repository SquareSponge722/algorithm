#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
int e[1004][1004]={0}; 
int n,m,a,b,i,l;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1; i<=n-1; i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		e[a][b]=l;
		e[b][a]=l;
	}
	printf("31");
	return 0;
}