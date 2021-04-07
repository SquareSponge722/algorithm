#include<cstdio>
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,i,j,s=0,b=4;
	long long a=1;
	scanf("%d%d",&n,&m);
	if(n==1||m==1)	{while(s<m*n)	a<<=1,s++;printf("%ld",a%1000000007);return 0;}
	else if(n==2||m==2) {while(s<m*n-2)	a<<=1,b<<=1,s++;printf("%ld",(b-a-n*m+m+n)%1000000007);return 0;}
	return 0;
}
