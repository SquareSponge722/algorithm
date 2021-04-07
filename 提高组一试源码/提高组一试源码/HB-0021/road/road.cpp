#include<cstdio>
#include<iostream>
#define N 100050
using namespace std;
int _min(int x,int y) {return x<y?x:y;}
int w[N],n,minn=999999999,cnt;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&w[i]);
		minn=_min(minn,w[i]);
	}
	for(int i=1;i<=n;i++) 
	if(w[i]!=minn) 
		cnt++;
	while(cnt)
	{
		for(int i=1;i<=n;i++)
		{
			int temp=999999999,temp1,temp2;
			if(w[i]==minn) continue;
			for(int j=i;j<=n;j++)
			{
				if(j==n&&w[j]!=minn) 
				{
					temp=_min(w[j],temp);
					temp1=j;
					break;
				}
				if(w[j]==minn) 
				{
					temp1=j-1;
					break;
				}
				temp=_min(w[j],temp);
			}
			temp2=temp-minn;
			ans+=temp2;
			for(int j=i;j<=temp1;j++)
			{
				w[j]-=temp2;
				if(w[j]==minn) cnt--;
			}
			i=temp1;
		}
	}
	printf("%lld",ans+minn);
	return 0;
}
