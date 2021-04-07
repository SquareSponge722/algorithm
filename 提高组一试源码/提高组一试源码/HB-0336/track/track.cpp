#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a_i=1,b_i=1,ans,cnt,tim;
int start[50100],end[50100],len[50100];
int e[110][110],book[10010],s[50010],sum[50010];

bool cmp(int a,int b){return a>b;}

namespace point1
{
	void dfs(int cur)
	{
		for(int t=1;t<=n;t++)
		{
			if(e[cur][t]!=0 && book[t]==0)
			{
				book[t]=1;
				cnt+=e[cur][t];
				dfs(t);
				book[t]=0;
				cnt-=e[cur][t];
			}
		}
		ans=ans<cnt?cnt:ans;
	}
	void work()
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i);
		}
		printf("%d",ans);
	}
}

namespace point2
{
	void work()
	{
		for(int k=1;k<=n;k++)
			s[k]=s[k-1]+len[k];
		for(int l=0;l<=n;l++)
			for(int r=l+1;r<=n;r++)
			{
				sum[++tim]=s[r]-s[l];
			}
		sort(sum+1,sum+n+1,cmp);
		printf("%d",sum[m]);
	}
}

namespace point3
{
	void work()
	{
		sort(len+1,len+n+1,cmp);
		ans=len[1]+len[m+1];
		printf("%d",ans);
	}
}

namespace point5
{
	void work()
	{
		sort(len+1,len+n+1,cmp);
		ans=len[1]+len[2];
		printf("%d",ans);
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d %d",&start[i],&end[i],&len[i]);
		if(start[i]!=1)
			a_i=0;
		if(end[i]!=start[i]+1)
			b_i=0;
		if(n<=50)
			e[start[i]][end[i]]=len[i];
	}
	if(m==1)
	{
		if(a_i==1)
			point5::work();//ok
		else
			point1::work();//ok
	}
	else
	{
		if(a_i==1)
			point3::work();//ok
		else
			if(b_i==1)
				point2::work();//ok
	}
	return 0;
}