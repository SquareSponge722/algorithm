#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
vector <int> t[5001];
bool flag[5001];
int ans[5001];
int d[10000];
bool tt[5001][5001];
void work(int step)
{
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==false)
			d[step++]=i;
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=d[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	}
	exit(0);
}
void dfs(int step,int now,int l)
{
	if(step==n+1)
	{
		for(int i=1; i<=n; i++)
			ans[i]=d[i];
	}
	else
	{
		for(int i=0; i<t[now].size(); i++)
		{
			int x=t[now][i];
			if(flag[x]==true && l!=0)
				dfs(step,d[l-1],l-1);
			if(x>ans[step] && d[step]!=0)
				break;
			d[step]=x;
			flag[x]=true;
			dfs(step+1,x,l+1);
			flag[x]=false;
			d[step]=0;
		}
		if(l==0)
			work(step);

	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		t[x].push_back(y);
		t[y].push_back(x);
	}
	for(int i=1; i<=n; i++)
		sort(t[i].begin(),t[i].end());
	for(int i=1; i<=n; i++)
	{
		d[1]=i;
		flag[i]=true;
		dfs(2,i,0);
		flag[i]=false;
		d[i]=0;
	}
	for(int i=1; i<=n; i++)
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	}
	return 0;
}
