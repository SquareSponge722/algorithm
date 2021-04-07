#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,a[100001],sum=0,j,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
for(int step=1;step<=n;step++)
	{
		if(a[step]==0)
		{
		j=step;
		for(int i=1;i<j;i++)
		{
		a[i]--;	
		}
		sum++;
		for(int i=j+1;i<=n;i++)
		{
			if(a[i]==0)
				i++;
			else
			{
			for(x=i;x<=n;x++)
		     a[x]--;
		     sum++;	
			}
		}
	    }
	    else
	    {
	    for(int i=1;i<=n;i++)
	    {
	    	a[i]--;
		}
		sum++;
		}
	}
	cout<<sum<<endl;
    return 0;
}
