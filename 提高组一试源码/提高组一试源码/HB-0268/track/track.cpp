#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    int n,m;
    int i,j,l;
    int ans=20001;
    int a[50001],b[50001],c[50001];
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        int x,y;
        cin>>a[i]>>b[i]>>c[i];
    }
    if(m==n-1)
    {
        for(i=1;i<=n;i++)
        {
			ans=min(ans,c[i]);
        }
    }
    else
    {
		for(i=1;i<=n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(a[j]<a[j+1])
				{
					l=a[j];
					a[j]=a[j+1];
					a[j+1]=l;
				}
			}
		}
        if(m<=n/2)
		{
			for(i=1;i<=m;i++)
			{
				for(j=m;j>=1&&j!=i;j--)
					ans=min(ans,c[i]+c[j]);
			}
		}
		else
		{
			i=1;
			while(c[i]>c[i-1]+c[m])
				i--;
			ans=c[i+1];
		}
    }
    cout<<ans;
    return 0;
}
