#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define run(a,b,c) for(a=b;a<=c;a++)
using namespace std;//70
const int MAXN=20005,MAXD=20005,INF=20005;
int N,k,MAX,a[MAXN],ans,book[MAXN];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		MAX=max(MAX,a[i]);
	}
	for(int i=1;i<=MAX;i++)
	{
		k=0;
		for(int j=1;j<=N;j++)
		{
			book[j]=0;
		}
		for(int j=1;j<=N;j++)
		{
			if(a[j]==0)
			{
				if(a[j-1]!=0&&!book[j-1])
				{
					k++;
					book[j-1]=1;
				}
				if(a[j+1]!=0&&!book[j+1])
				{
					k++;
					book[j+1]=1;
				}
			}
		}
		for(int j=1;j<=N;j++)
		{
			if(a[j]!=0)
			{
				a[j]--;
			}
		}
		k=max(k,1);
//		printf("k:%d\n",k);
//		for(int j=1;j<=N;j++)	
//		printf("%d ",a[j]);
//		puts("\n");
		ans+=k;
	}
	printf("%d",ans);
	return 0;
}
