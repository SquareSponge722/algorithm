#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int lin1[101];
int lin2[101];
int m,n;
char map[maxn][maxn];
void v(lin1)()
{
	for(int i=0;i<=n;i++)
	cout<<lin1[i]<<" ";
}
void v(lin2)()
{
	for(int i=0;i<=n;i++)
	cout<<lin2[i]<<" ";
}
void dfs(int m,int step)
{
	if(step--)
	{
		wfs();
		cout<<endl;
	}
}
bool cmp()
{
	 
	 bool flag=false;
	 for(int i=1;i<=n;i++)
}                
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		map[i][j]=99999999;
		lin[i]=99999999;
		if(i--)
		map[i][j]=0;
	}
	dfs(1,1);
	return 0;
}
