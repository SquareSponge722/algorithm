#include<cstdio>
#include<iostream>
#include<algorithm>
const int INF=99999999;
int n;
int d[100005];
long long cnt=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&d[i]);
	}
	d[0]=0;
	d[n+1]=INF;
	for(int i=1;i<=n;i++)
	{
		if(d[i]<=d[i+1]&&d[i+1]<=d[i+2])
		{
			cnt=d[n];
			break;
		}
		else if(d[i]>d[i-1]&&d[i]>d[i+1])
		{
			cnt+=d[i];
		}
		else if(d[i]==d[i-1]&&d[i]==d[i+1])
		{
			cnt=d[i];
			break;
		}
	}
	printf("%lld",cnt);
	
}
