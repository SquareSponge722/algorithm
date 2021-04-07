#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
vector <int > d[5001];
bool id[5001];
bool use[5001];
vector <int > sx;
int m,n;
void dfs(int bh)
{
	if(sx.size()==n)
	return;
	if(d[bh].size()>1) 
	{
		sort(d[bh].begin(),d[bh].end());
		for(int i=0;i<d[bh].size();i++)
		{
			if(!use[i]);
			{
				sx.push_back(d[bh][i]);
				use[i]=true;
				break;
			}
		}	
		if(d[d[bh][0]].size()>1)  
		{
			sort(d[d[bh][0]].begin(),d[d[bh][0]].end());
			if(d[d[bh][0]][0]>d[bh][2]) 
			{
				sx.push_back(d[bh][2]); 
				dfs(d[bh][2]);
			}
			else
			{
				sx.push_back(d[d[bh][0]][0]); 
				dfs(d[d[bh][0]][0]);
			}
		}
		else
		{
			if(d[d[bh][0]][0]>d[bh][1])
			{
				sx.push_back(d[bh][1]);
				dfs(d[bh][1]);
			}
			else
			{
				sx.push_back(d[d[bh][0]][0]);
				dfs(d[d[bh][0]][0]);
			}
		}
	}
	else
	{
		sx.push_back(bh);
		dfs(d[bh][0]);
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		id[u]=true,id[v]=true;
		d[u].push_back(v);
		d[v].push_back(u);
	}
	int min=5001;
	for(int i=1;i<=n;i++)
	{
		if(id[i])
		{
			min=i;
			break;
		}
	}
	use[min]=true;
	dfs(min);
	for(int i=0;i<sx.size();i++)
	printf("%d ",sx[i]);
	printf("\n");
	return 0;
}
