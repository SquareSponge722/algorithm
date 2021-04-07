#include <bits/stdc++.h>
using namespace std;
int k,t,minn,flag;
int n,m;
int a[10005],ans[10005],b[10005];

int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=2*m;i++)
	int k=1,t=1;
	while(t<n)
	{
		minn=9999;
		for(int i=1;i<=2*m;i++)
		if(a[i]==k&&b[i+1])
		{
			if(i%2==0)
			{
				if(a[i-1]<minn)
				minn=a[i-1];
				flag=i;
			
			}
			else
			{
				if(a[i+1]<minn)
				{
					minn=a[i+1];
					flag=i;
				}
				
			}
			ans[t]=a[i];
		}
			cout<<minn<<endl;
		 	b[(flag+1)/2]=1;
			t++;
			k=minn;
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<' ';
	return 0;
}
