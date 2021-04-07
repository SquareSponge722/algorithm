#include <cstdio>
#include <algorithm>
using namespace std;
int map[5001][5001],book[5001];
int n,m,l,cnt,sum;
int a[5005];
void dfs(int id)
{
	cnt=max(cnt,l);
	for(int i=1;i<=n;i++)
	{
		if(map[id][i]!=0&&!book[i])
		{
			book[i]++;
			l+=map[id][i];
			dfs(i);
			book[i]--;
			l-=map[id][i];
		}
	}
}
int main()
{
	int flag=1;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=map[b][a]=c;
		sum+=c;
		if(a!=0) flag=0;
	}
	if(flag)
	{
		for(int i=2;i<=n;i++)
			a[i]=map[1][i];
		sort(a+2,a+n+1);
		cnt=a[n-m+1];
	}	
	else if(m==1)
	for(int i=1;i<=n;i++)
	{
		book[i]++;
		dfs(i);
		book[i]--;
	}
	else cnt=sum*2/(3*m);
	printf("%d",cnt);
	return 0;
}
