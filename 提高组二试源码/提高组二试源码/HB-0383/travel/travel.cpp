#include<iostream>
using namespace std;
const int maxn=5001;
int x,n,m,u,v,arr[maxn][maxn],first[maxn],log[maxn],last[maxn];
void dfs(int a)
{
	int next=maxn;
	for(int i=1;i<=n;i++)
		if(arr[a][i]==1&&i<next&&last[a]!=i&&last[i]!=a) next=i;
	if(next<maxn)
	{
		log[++x]=next;
		first[next]=a;
		last[a]=next;
		dfs(next);
	}
	else if(next==maxn)
	{
		for(int i=1;i<=n;i++)
		{
			if(first[i]==a)
			{
				last[a]=i;
				dfs(i);
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		arr[u][v]=1;
		arr[v][u]=1;
	}
	log[++x]=1;
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d ",log[i]);
	return 0;
}
