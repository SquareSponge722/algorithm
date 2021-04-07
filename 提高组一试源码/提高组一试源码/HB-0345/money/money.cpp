#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[1005],n,stack[1005],tot;
namespace task2
{
	bool flag;
	void pd(long long num,long long deep,long long sum)
	{
		if(deep==tot+1)
		{
			if(sum==num) flag=1;
			return;
		}
		for(long long i=0;i*stack[deep]+sum<=num;i++) 
		{
		    pd(num,deep+1,sum+i*stack[deep]);
		    if(flag) return;
		}
	}
	void work()
	{
		tot=0;
		sort(a+1,a+n+1);
		stack[1]=a[1],tot=1;
		for(long long i=2;i<=n;i++)
		{
			flag=0;
			pd(a[i],1,0);
			if(!flag) stack[++tot]=a[i];
		}
		cout<<tot<<endl;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n;
		for(long long j=1;j<=n;j++) cin>>a[j];
		task2::work();
	}
	return 0;
}
