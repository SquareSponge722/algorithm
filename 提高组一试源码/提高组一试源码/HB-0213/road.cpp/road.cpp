#include<bits/stdc++.h>
using namespace std;
int ans=99999;
	int main()
	{
		freopen("road.in","r","stdin");
		freopen("road.out","r","stdout");
		int n,i,a[100001],step;
		int m=true;
		cin>>n;
		cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				m=false;
				break;
			}
		}
		if(m)
		{
			ans=m;
			ans=min(ans,step);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				m=true;
				continue;
			}
		}
		if(a[i]|=0)
		{
			m=false;
		}
		if(ans=m)
		cout<<ans;
		return 0;
	}	
