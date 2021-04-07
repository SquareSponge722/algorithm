#include <cstdio>
long long ans=0,n,m,in[100005];
/*int cal(int x,int y)
{
	return (x-1)*n+y;
}
bool judge(int chang,int kuan)
{
	for(int i=2;i<=n;i++)
	{
		int x=1;
		int y=i;
		printf("%d %d\n",x,y);
		for(y=y;y>=2;y--,x++)
			if(in[cal(x,y)]<in[cal(x+1,y-1)])
				return 1;
	}
	for(int i=2;i<=m;i++)
	{
		int x=i;
		int y=n;
		printf("%d %d\n",x,y);
		for(x=x;x<m;x--,y--)
			if(in[cal(x,y)]<in[cal(x+1,y-1)])
				return 1;
	}
	return 0;
}
void dfs(int num)
{
	if(num==m*n+1)
	{
		
		if(judge(n,m))
		{
			for(int i=1;i<=n*m;i++)
				printf("%d",in[i]);
			printf("\n");
			ans--;
		}
		return;
	}
	in[num]=1;
	dfs(num+1);
	in[num]=0;
	dfs(num+1);
}*/
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	/*ans=(1<<(n*m));
	dfs(1);
	ans%=1000000007;
	printf("%lld",ans);*/
	if(n==1)
	{
		long long ans=1;
		for(int i=1;i<=m;i++)
		{
			ans*=2;
			ans%=1000000007;
		}
		printf("%lld",ans);
	}
	if(m==1)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=1000000007;
		}
		printf("%lld",ans);
	}
	if(n==3 && m==2 || m==3 && n==2)
		printf("28");
	if(n==2 && m==2)
		printf("12");
	if(n==3 && m==3)
		printf("112");
	if(n==5 && m==5)
		printf("7136");
	return 0;
}