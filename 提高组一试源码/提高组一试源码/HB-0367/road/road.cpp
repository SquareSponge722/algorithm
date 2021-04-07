#include<iostream>
#include<cstdio>
using namespace std;
const int mn=100005;
long long j,i,ans,n,k=1;
long long d[mn];
void jian(int l,int r)
{
	if(l>r||d[l]<=-1||d[r]<=-1)return ;
	if(l<r)
	{
		for(int h=1; h<=100000; h++)
		{
			ans++;
			for(int m=l; m<=r; m++)
			{
				d[m]--;
				if(d[m]<=0)
				{
					for(int p=m+1; p<=r; p++)
					{
						d[p]--;
					}
					jian(l,m-1);
					jian(m+1,r);
					return;
				}
				/*if(d[m]<=-1)
				{
					jian(m+1,r);
					return;
				}*/
			}
		}
	}
	else
	{
		ans+=d[l];
	}
	return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n;
	for( i=1; i<=n; i++)
	{
		cin>>d[i];
	///}
	///for(int i=1; i<=n; i++)
	///{
		if(d[i]==0)
		{
			jian(k,i-1);
			k=i+1;
		}
		if(i==n)
		{
			jian(k,i);
		}

	}
	cout<<ans;
	return 0;
}
