#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int d[120000];
int now;
int day;
void dfs(int x,int y)
{
	if(now==0)
		return;
	if(x>y)
		return;
	if(x==y)
	{
		day+=d[x];
		d[x]=0;
		now--;
		return;
	}
	int m=9999999;
	int flag[100000]={0};
	int count=0;
	for(int i=x;i<=y;i++)
		if(d[i]>0)
			m=min(m,d[i]);
	flag[count++]=x-1;
	day+=m;
	for(int i=x;i<=y;i++)
	{
		d[i]-=m;
		if(d[i]==0)
		{
			flag[count++]=i;
			now--;
		}
	}
	for(int i=0;i+1<count;i++)
		dfs(flag[i]+1,flag[i+1]-1);
	dfs(flag[count-1]+1,y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	now=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	dfs(1,n);
	printf("%d",day);
	return 0;
}
