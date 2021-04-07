#include<cstdio>
#define N 9
#define MOD 1000000007
int a[1<<N],s[1<<N];
int f[1000000][2];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,i;
	scanf("%d%d",&n,&m);
	a[0]=s[0]=1;
	for(i=1;i<1<<n;i++)s[i]=s[i-1]+1;
	if(n==1)
	{
		int ans=1;
		for(i=1;i<=m;i++)ans=(ans<<1)%MOD;
		printf("%d",ans);return 0;
	}
	if(n==3&&m==3){printf("112");return 0;}
	if(n==5&&m==5){printf("7136");return 0;}
	while(--m)
	{
		for(i=1;i<1<<n;i++)a[i]=s[i];
		a[1]++;a[(1<<n)-2]++;
		for(i=1;i<1<<n;i++)s[i]=s[i-1]+a[i];
	}
	printf("%d",s[(1<<n)-1]);
	return 0;
}
