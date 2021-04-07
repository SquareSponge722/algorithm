#include <bits/stdc++.h>
using namespace std;
int n,m;
char type[3];
int city[100001],p[100001];
int qaq[101][101];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		qaq[x][y]=1;
		qaq[y][x]=1;
	}
	memset(city,0,sizeof(city));
	while(m--)
	{
		int x,y,a,b;
		int ans=0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x)
		{
			city[a]=1;
			ans+=p[a];
		}
		if(y)
		{
			city[b]=1;
			ans+=p[b];
		}
		for(int i=1;i<n;i++) 
		{
			if(city[i]==0 && city[i+1]==0 && city[i-1]==0)
			{
				city[i]++;
				ans+=p[i];
			}
		}
		printf("%d",ans);
	}
	return 0;
}
