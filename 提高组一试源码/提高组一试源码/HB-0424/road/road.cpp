#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=0;
int a[100010];
int dot,minn=30000;
void hc(int l,int r)
{
	if(l==r)
	{
		ans+=a[l];
		a[l]=0;
		return;
	}
	minn=30000;
	for(int m=l;m<=r;m++)
		if(a[m]<minn)
		{
			dot=m;
			minn=a[m];
		}
	ans+=minn;
	for(int m=l;m<=r;m++)
		a[m]-=minn;
	hc(dot+1,r);
	hc(l,dot-1);
	return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
   		scanf("%d",&a[i]);
	}
    hc(0,n-1);
    cout<<ans;
    return 0;
}
