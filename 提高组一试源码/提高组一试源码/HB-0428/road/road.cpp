#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
int a[100004]={0},n,ans=0,i,j,k,f,e,l,flag=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int p,q;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&p);
		a[i]=p;
	}
	while(1>0)
    {
	    if(flag==0) break;
		flag=0;
		for(i=1; i<=n; i++)
		{
			if(a[i]!=0)
			{
				ans++;
				f=i;
				for(j=f; j<=n+1; j++)
				{
					if(a[j]==0)
					{
						e=j-1;
						break;
					}
				}
				for(k=f; k<=e; k++)
				{
					q=a[k];
					a[k]=q-1;
				}
				flag=1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}