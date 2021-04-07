#include<bits/stdc++.h>
#define re register
using namespace std;
int n,a[1001000],maxn,ans=0,num=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
	{
		maxn=max(maxn,a[i]);
		if(a[i]<a[i+1])
		{
			int k=i;			
			for(int l=k+1; l<=n; l++)
			{
				a[l]-=a[i];
				if(a[l]<0) a[l]=0;
			}
			for(int l=1; l<=i; l++)
			a[l]=0;
			ans+=maxn;
			maxn=0;
		}
	}
	for(int i=1;i<=n;i++)
	maxn=max(maxn,a[i]);
	cout<<ans+maxn<<endl;
}
/*
8
1 2 3 4 5 6 7 8

16
1 2 3 4 5 6 7 8 8 7 6 5 4 3 2 1 

*/
