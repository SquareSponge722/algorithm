#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define MAXN 50005
using namespace std;
int n,m,ans=0,maxxx=0;
vector <pair<int,int> > ms[MAXN];
int cnt[MAXN],book[MAXN];
void dfs(int a,int b,int s)
{
	if(a==b) 
	{
		ans=max(ans,s);
		return ;
	}
	if(book[a]) return ;
	book[a]=1;
	for(int i=0;i<ms[a].size();i++)
	{
		dfs(ms[a][i].first,b,s+ms[a][i].second);
	}
	book[a]=0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int a,b,v;
		scanf("%d %d %d",&a,&b,&v);
		ms[a].push_back(make_pair(b,v));
		ms[b].push_back(make_pair(a,v));
		cnt[a]++; cnt[b]++;
		maxxx+=v;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==1)
			for(int j=1;j<=n;j++)
			{
				if(cnt[j]==1&&i!=j)
				{
					dfs(i,j,0);
				}
			}
		}
		printf("%d\n",ans);
	}
	else
	{
		printf("maxxx\n");
	}
	return 0;
}
