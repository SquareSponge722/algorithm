#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int minn=99999999,xb;
long long ans=0;
void ef(int L,int R)
{
	if(L==R)
	{
		ans+=a[L];
		//cout<<"ANS"<<ans<<endl;
		a[L]=0;
		return;
	}
	if(a[L]==0 || a[R]==0 || L>R)
	{
		return;
	}
	minn=99999999;
	for(int i=L;i<=R;i++)
	{
		//cout<<"###"<<endl;
		if(a[i]!=0 && minn>a[i])
		{
			minn=a[i];
			xb=i;
		}
	}
	for(int i=L;i<=R;i++)	a[i]-=minn;
	ans+=minn;
	ef(L,xb-1);
	ef(xb+1,R);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(minn>a[i])
		{
			minn=a[i];
			xb=i;
		}
	}
	ans+=minn;
	//cout<<ans<<endl;
	for(int i=1;i<=n;i++)	a[i]-=minn;
	
	int xb1=xb,xb2=xb;
	minn=99999999;
	ef(1,xb1-1);//ok~
	//cout<<"&&&"<<ans<<endl;
	minn=99999999;
	ef(xb2+1,n);
	cout<<ans;
	return 0;
}
