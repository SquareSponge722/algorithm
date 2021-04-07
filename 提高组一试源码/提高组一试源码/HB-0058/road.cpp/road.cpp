#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int lu[100003];
int n,ans=0,pd=0;
int m=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>lu[i];
	while(m==1)
	{
		pd=0;
		for(int i=1;i<=n;i++)
		{
			if(lu[i]>0&&lu[i+1]!=0)
				lu[i]=lu[i]-1;
			if(lu[i]>0&&lu[i+1]==0)
			{
				lu[i]--;
				ans++;
			}
			if(lu[i]==0)
			{
				pd++;
				if(pd==n)
					m=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

