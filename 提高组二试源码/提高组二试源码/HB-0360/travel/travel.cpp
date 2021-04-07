#include<cstdio>
#include<cstdlib>

using namespace std;
int n,m,rest;
bool d[5001][5001];
int r[5001],pos=0,zm[5001];
int man[5001];
bool visit[5001];
bool first=true;
bool found(int x)
{
	for(int j=0;j<pos;j++)
		if(r[j]==x)
			return true;
	return false;
}
void dfs(int s)
{
	if(pos==n)
	{
		if(first)
		{
			for(int i=0;i<n;i++)
				zm[i]=r[i];
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(r[i]>zm[i])
					return ;
				if(r[i]<zm[i])
				{
					for(int i=0;i<n;i++)
						zm[i]=r[i];
					first=false;
					return ;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(d[man[s-1]][i]&&!visit[i])
			{
				man[s]=i;
				if(!found(man[s]))
				{
					r[pos]=i;
					pos++;
				}
				visit[i]=true;
				dfs(s+1);
				visit[i]=false;
				///
		//		if(found(i))
		//			visit[i]=true;
			}
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	rest=n;
	int a,b,min=999999;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		d[a][b]=true;
		d[b][a]=true;
		if(a<min) min=a;
		if(b<min) min=b;
	}
	r[0]=min;pos++;
	man[0]=min;
	visit[min]=true;
	dfs(1);
	for(int i=0;i<n;i++)
		printf("%d ",zm[i]);
	return 0;
}
