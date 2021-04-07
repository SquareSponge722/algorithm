#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
int n,a[100010],ans;
int main()
{
	fin>>n;
	int minn=99999999;int maxx=0;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
		if(a[i]>maxx)
		maxx=a[i];
		if(a[i]<minn)
		minn=a[i];
	}
	for(int i=maxx;i>minn;i--)
	{
		for(int j=1;j<=n;j++)
		{
		    if(a[j]>=i&&a[j-1]>=i)
			{
				continue;
			}
			if(a[j]>=i)
			{
				ans++;
			}
			
		}
	}
	
	ans+=minn;
	fout<<ans;
	return 0;
}
