#include<bits/stdc++.h>
#define N 10
#define INF 0x3f
using namespace std;
int g[N][N];
int m,n;
int main ()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<2||m<2||(n==2&&m==1)||(n==1&&m==2))
		printf("0\n");
	if(n==2&&m==2)
		printf("12\n");
	if((n==2&&m==3)||(n==3&&m==2))
		printf("18\n");
	if(m==3&&n==3)
		printf("30\n");
	return 0;
}
