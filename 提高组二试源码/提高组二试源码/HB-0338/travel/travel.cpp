#include<bits/stdc++.h>
using namespace std;
int m,n,fa,son,edge[5005][5005],sum[5005],b[5001][5001],pre[5001],flag;
bool iswa[5005],pd[5001],eb[5001][5001];
queue<int> q;

void ring(int fa)
{
	if(flag) return;
	if(pd[fa]){flag=fa;return;}
	pd[fa]=1;
	for(int i=1;i<=sum[fa];i++)
	{
	if(!eb[fa][edge[fa][i]])
	  pre[edge[fa][i]]=fa,
	  eb[fa][i]=eb[edge[fa][i]][fa]=1,
	  ring(edge[fa][i]);
	if(flag) return;
	}
}


void dfs(int fa)
{
	if(!iswa[fa])
	{
		q.push(fa);
		iswa[fa]=1;
	}
	for(int i=1;i<=sum[fa];i++)
	  if(!iswa[edge[fa][i]]) 
	  dfs(edge[fa][i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
	{
	    scanf("%d %d",&fa,&son);
	    edge[fa][++sum[fa]]=son;
	    edge[son][++sum[son]]=fa;
	}	    
	for(int i=1;i<=n;i++)
	   sort(edge[i]+1,edge[i]+1+sum[i]);
	if(m==n) ring(1);
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
			
	}
	return 0;
}
