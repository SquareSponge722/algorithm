#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,d[1005],day,book[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	n=0;day=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	
	for(int i=1;i<=n+1;i++)
	{
		d[n+1]=0;
		if(d[n]==0) break;
		if(d[i]!=0)
		{
			continue;
		}
        while(d[i]!=0)
        break;
        	
		
		while(d[i]==0)
		{
			for(int j=1;j<=i;j++)
			{
				d[j]--;
				day++;
			}
		}
		
	}
	printf("%d",day+2);
	return 0;
}
