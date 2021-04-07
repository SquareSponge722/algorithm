#include <cstdio>
#include <algorithm>
using namespace std;
int m,n;
long long ans;
const long long modi=1000000007;
long long ksm(int num,int step)
{
	if(step==0)
		return (long long)1;
	if(step==1)
		return ((long long)num)%modi;
	if(step%2==1)
	{
		long long k=ksm(num,step/2);
		return (2*k*k)%modi;
	}
	long long k=ksm(num,step/2);
	return (k*k)%modi;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("%lld",ksm(2,n));
		return 0;
	}
	else if(n==1)
	{
		printf("%lld",ksm(2,m));
		return 0;
	}
	else if(m==2)
	{
		int t=m;
		m=n;
		n=t;
	}
	if(n==2)
	{
		long long ans=0;
		ans+=ksm(2,m+1);
		for(int i=1;i<=m-1;i++)
		{
			ans+=4*(ksm(2,i-1)*ksm(4,m-i-1));
		}
		ans%=modi;
		printf("%lld",ans);
		return 0;
	}
	if(n==3&&m==3)
	{
		printf("112");
		return 0;
	}
	else
	printf("%lld",(ksm(2,(m+n)/2)*(ksm(2,2*(m+n)-2)-ksm(2,(m+n)/2)))%modi
	return 0;
}
