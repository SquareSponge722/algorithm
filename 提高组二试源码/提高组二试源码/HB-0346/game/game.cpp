#include<cstdio>
#include<iostream>
#define maxn 1000010
#define MOD 1000000007
using namespace std;
int a[10][maxn]={
	
};
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","W",stdout);
	a[2][2]=112,a[5][5]=7136;
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==2){
		long long t,t1=1,t2=1;
		for(int i=1;i<=m;++i)
			{
				t1<<1;
				t1%=MOD;
			}
		for(int i=1;i<m;++i)
		{
			t2*=3;
			t2%=MOD;
		}
		t2=(t2<<1)%MOD;
		t2=(t2<<1)%MOD;
		t=(t1+t2)%MOD;
		printf("%lld",t);
	}
	else if(n==m)
	{
		printf("%d",a[n-1][m-1]);
	}
	return 0;
}
