#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int n;
int a[100005];
long long ans;
int minn(int x,int y)
{
	int t=a[x];
	for(int i=x;i<=y;i++)
		t=min(t,a[i]);
	return t;
}
void hs(int x,int y)
{
	int t=0;
	int t1;
	for(int i=x;i<=y;i++)
		if(a[i+1]==0)
		{
			t=minn(x,i);
			t1=i;
			ans+=t;
			break;
		}
	for(int i=x;i<=t1;i++)
		a[i]-=t;
/*
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
*/
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
			flag=1;
	}			
	if(flag==0)
		printf("%lld\n",ans);
	else
	{
		int p;
		for(int i=1;i<=n;i++)
			if(a[i]!=0)
			{
				p=i;
				break;
			}
		for(int i=p;i<=n;i++)
			if(a[i+1]==0)
			{
				hs(p,i);
				break;
			} 
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	hs(1,n);
	return 0;
}
