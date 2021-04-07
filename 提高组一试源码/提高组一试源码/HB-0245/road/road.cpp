#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[100001];
void tian(int l,int r)
{
	if(l>r)
	return;
	else
	if(l<r)
	{int sum=99999999;
	int flag=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]<sum)
		{
			sum=a[i];
			flag=i;
		}
	}
	ans+=sum;
	for(int i=l;i<=r;i++)
	a[i]-=sum;
	tian(l,flag-1);
	tian(flag+1,r);
	return;
	}
	else
	if(l==r)
	{
		ans+=a[l];
		a[l]=0;
		return;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	tian(1,n);
	cout<<ans;
	return 0;
}
