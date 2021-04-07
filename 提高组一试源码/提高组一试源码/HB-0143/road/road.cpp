#include<iostream>
#include<cstdio>
using namespace std;
long long n,i,j;
int d[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int s,max=1;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>d[i];
	for(i=2;i<=n;i++)
	{
		if(d[i]>=d[i-1])
		   max=d[i];
	}
	for(i=1;i<=max;i++)
	{
		for(i=1;i<=n;i++)
		{
			if(d[i]!=0)
			d[i]--;
			else
			{
				if(d[i]==0&&i!=1&&i!=n)
				s=s+1;
			}
		}
	}
	max=max+s;
    cout<<max;
	return 0;
}
