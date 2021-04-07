#include<bits/stdc++.h>
using namespace std;
int n,m,fa,son,edge[5001][5001],sum[5001],b[5001][5001],pre[5001],flag,l,a[5001];
int ans[5001];
bool iswa[5001],pd[5001],eb[5001][5001];
queue<int>q;
int cmp(int *a,int *b,int len)
{
	int i=1;
	while(a[i]==b[i]&&i<=len)i++;
	if(i==len+1)return 0;
	else
	{
		if(a[i]<b[i])return -1;
		return 1;
	}
}
void copy(int *a,int len){for(int i=1;i<=len;i++)ans[i]=a[i];}
void ring(int fa)
{
	if(flag)return;
	if(pd[fa]){flag=fa;return;}
	pd[fa]=1;
	for(int i=1;i<=sum[fa];i++)
	{
		if(!eb[fa][edge[fa][i]])
			pre[edge[fa][i]]=fa,
			eb[fa][edge[fa][i]]=eb[edge[fa][i]][fa]=1,
			ring(edge[fa][i]);
		if(flag)return;
	}
		
}
void dfs(int fa)
{
	if(!iswa[fa])
	{
		if(m==n-1)q.push(fa);
		else a[++l]=fa;
		iswa[fa]=1;
	}
	for(int i=1;i<=sum[fa];i++)
		if((!iswa[edge[fa][i]])&&b[fa][edge[fa][i]])
			dfs(edge[fa][i]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&fa,&son);
		edge[fa][++sum[fa]]=son;
		edge[son][++sum[son]]=fa;
		b[fa][son]=b[son][fa]=1;
	}
	for(int i=1;i<=n;i++)
		sort(edge[i]+1,edge[i]+1+sum[i]);	
	if(m==n)ring(1);
	if(m==n-1)
	{
		dfs(1);
		while(!q.empty())
		{
			printf("%d ",q.front());
			q.pop();
		}
		return 0;
	}
	else
	{
		int ok=0;
		for(int i=1;i<=n;i++)ans[i]=999999;
		for(int i=flag;1;i=pre[i])
		{
			if(ok&&i==flag)break;
			l=0;
			memset(iswa,0,sizeof(iswa));
			b[i][pre[i]]=b[pre[i]][i]=0;
			dfs(1);
			if(cmp(ans,a,l)==1)copy(a,l);
			b[i][pre[i]]=b[pre[i]][i]=1;
			ok=1;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		return 0;
	}
	return 0;
}
