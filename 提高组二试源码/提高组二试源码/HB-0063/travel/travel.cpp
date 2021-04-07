#include<bits/stdc++.h>
using namespace std;
vector <int>path[5005];
int n,m,u,v,l,city[5005],num;
priority_queue<int> q;
bool f[5005];
int work(int x)
{
	if(x==0) return 0;
	int l=path[x].size();
	for(int i=0;i<l;i++)
	{
		u=path[x][i];
		if(city[u]==0&&u!=1)
		{
			printf("%d ",u);
			city[u]=x;
			work(u);
		}
	}
	return work(city[x]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	//cout<<n<<" "<<m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		path[u].push_back(v);
		path[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		l=path[i].size();
		for(int j=0;j<l;j++)
			for(int k=j+1;k<l;k++)
				if(path[i][j]>path[i][k])
				{
					int x=path[i][j];
					path[i][j]=path[i][k];
					path[i][k]=x;
				}
	}
	printf("1 ");
	work(1);
	return 0;
}
