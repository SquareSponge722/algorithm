#include<iostream>
#include<cstdio>
using namespace std;
int m,n,x,y;
int map[1010][1010];
bool b[1010];
int lin1[1010];
int lin2[1010];
void save()
{
	for(int i=1;i<n;i++)
		lin2[i]=lin1[i];
}
bool cmp()
{
	int t=0; 
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(lin2[i]!=lin1[i])
		{
			t=i;
			break;
		}
	if(t!=0)
    	if(lin2[t]>lin1[t])
        	flag=true;
	return flag;
}
void dfs(int nx,int step)
{
	if(step==n)
	{
		if(cmp())
			save();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(map[nx][i]==1&&(!b[i]))
		{
			b[i]=true;
			lin1[step]=i;
			dfs(i,step+1);
			b[i]=false;
		}
	}
	return;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			map[i][j]=99999999;
			lin2[i]=99999999;
			if(i==j)
				map[i][j]=0;
		}
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
		map[y][x]=1;
	}
	dfs(1,1);
	cout<<1<<' ';
	for(int i=1;i<n;i++)
		cout<<lin2[i]<<' ';
    return 0;
}
