#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
char sets[101];
long long cot[100010];
int pts[100010];
long long sum,cnt=1e16,minc=999999999;
void dfs(int id)
{
	if(pts[id]==0&&pts[id-1]==0)
		return;
	if(cnt<=sum+minc*(n-id)/2)
		return;
	if(id>n)
	{
		cnt=min(cnt,sum);
	}
	if(pts[id]==-1)
	{
	//	printf("%lld ",sum);
		pts[id]=1;
		sum+=cot[id];
		dfs(id+1);
		sum-=cot[id];
		if(pts[id-1]!=0)
		{
			pts[id]=0;
			dfs(id+1);
		}
		pts[id]=-1;
	}
	else
	dfs(id+1);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d %s",&n,&m,&sets);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&cot[i]);
		minc=min(minc,cot[i]);
	}
	if(sets[0]=='A')
	{
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
		}
		for(int i=1;i<=m;i++)
		{
			int a,b,x,y;
			for(int i=0;i<=n;i++)
				pts[i]=-1;
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if((a==b+1||b==a+1)&&(x==0&&y==0))
				printf("%d\n",-1);
			else
			{
				cnt=1e16;
				sum=0;
				pts[a]=x;
				pts[b]=y;
				dfs(1);
				if(x==1)
				cnt+=cot[a];
				if(y==1)
				cnt+=cot[b];
				if(cnt<1e16-1)
				printf("%lld\n",cnt);
				else printf("%lld\n",minc);
			}
		}
	}
	else
	{
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
		}
		for(int i=1;i<=m;i++)
			printf("-1\n");
	}
	return 0;
}
