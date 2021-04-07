
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,fa,son,edge[5001][5001],sum[5001],b[5001][5001],pre[5001][5001],flag,l,ans[5001],a[5001];
bool iswa[5001],flag,pd[5001],eb[5001][5001];
queue<int>q;
bool cmp(int *a,int *b)
{
	int i;
	while(a[i]=b[i] && i<=len) i++;
	if(i==len+1) return 0;
	else
	{
		if(a[i]<b[i]) return 0;
		}
void ring( int fa)
{
	if(flag)return;
	if(pd[fa]){flag=fa;return;}
	pd[fa]=1;
	for(int i=1;i<=sum[fa];i++)
	{
		if(!eb[fa][edge[fa][i]])
		{
			pre[edge[fa][i]]=fa;
			eb[f]a[edge[fa[i]]=eb 
		}
	}
}
			
void dfs	(int fa)
{
if(!iswa[fa])
{
if(m==n-1)q.push(fa);}
}
	}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&fa,&son);
	}
	for(int i=1;i<=n;i++)
	{
		sort(edge[i]+1,edge[i]+1+sum[i]);
	}
	if(m==n)
	{
		ring(1);
	}
	if(m==n-1)
	{
		dfs(1);
		while(!q.empty())
		{
			printf("%d",q.front());
			q.pop();
		}
	return 0;
}
 
	