#include<bits/stdc++.h>
using namespace std;
int ans,a[105],T,n,minn,maxx;
bool ok,b[25005];
void work(int x)
{
	for(int i=2;i*x<=maxx;i++)
	{
		b[i*x]=1;
	}
	return ;
}
void work2(int x,int l)
{
	if(x==0)
	{
		ans--;
		ok=0;
		return ;
	}
	if(ok==0)return ;
	for(int i=l;i>=1;i--)
	{
		if(ok==0) break;
		if(x-a[i]>=0)
		{
			work2(x-a[i],i);
		}
		
	}
	return ;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		minn=9999,ans=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(minn>a[i])minn=a[i];
			if(maxx<a[i])maxx=a[i];
		}
		if(minn==1)
		{
			printf("1\n");
			continue;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			if(!b[a[i]])
			{
				work(a[i]);
			}
			else
			{
				ans--;
			}
		}
	/*	for(int i=1;i<=20;i++)
			cout<<i<<" "<<b[i]<<endl;*/
		for(int i=2;i<=n;i++)
		{
			if(!b[a[i]])
			{
				ok=1;
				work2(a[i],i-1);
			}
		}
		printf("%d\n",ans);
	}
}
