#include<cstdio>
#include<cmath>

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	printf("%d",pow(2,m*n)-(m-1)*m*n);
	return 0;
}
