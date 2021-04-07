#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector<int> tmp[5005];
vector<int> sq;
int book[5005];
int cont;
bool mp[5005][5005]={0};
//vector<int> pro[5005];

bool reachable(int cur,int x)
{
	//printf("\nreachable ... cur:%d target:%d",cur, x);
	if(cur==-1) return false;
	//if(book[tmp[x][0]]==0) return false;
	if(mp[cur][x]==1)
	{	
		book[x] = cur;	 
		return true;	
	}
	//return reachable(book[cur],x);
	while(cur!=-1)
	{
		cur = book[cur];
		if(mp[cur][x]==1)
		{	
			book[x] = cur;	 
			return true;	
		}
	}
	return false;
}

void dfs(int x)
{
//	for(int i=0;i<pro[x].size();i++)
//	{
//		if(book[pro[x][i]] == 0)
//		{
//			sq.push_back(i);
//			cont++;
//			if(cont==n) return ;
//			dfs(i);
//			cont--;
//			book[sq[sq.size()-1]] = 0;	 
//			sq.pop_back();
//		}
//	}
	for(int i=2;i<=n;i++)
	{
		if(book[i]==0 && reachable(x,i))
		{
			sq.push_back(i);
			cont++;
			if(cont==n) return ;
			dfs(i);
			cont--;
			book[sq[sq.size()-1]] = 0;	 
			sq.pop_back();
		}
	}
}


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ts,te;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&ts,&te);
		mp[ts][te] = 1;
		mp[te][ts] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]==1) tmp[i].push_back(j);
		}
//		if(tmp[i].size()==1)
//		{
//			pro[tmp[i][0]].push_back(i);
//		}
	}
	int cur=1;
	sq.push_back(1);
	book[1] = -1;
	cont = 1;
	
	dfs(1);
	
	for(int i=0;i<sq.size();i++)
	{
		printf("%d ",sq[i]);
	}
	return 0;
}
