#include<cstdio>
#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=300001;
int p[MAXN];
int a[MAXN],b[MAXN],x[MAXN],y[MAXN];
bool vis[MAXN];
bool mustt[MAXN];
bool mycheck()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i-1]==false&&vis[i+1]==false)
		{
			return false;
		}
	}
	return true;
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    string s;
    int n,m;
    vis[0]=true;
    cin>>n>>m>>s;
    vis[n+1]=true;
    for(int i=1;i<=n;i++)
    {
    	cin>>p[i];
	}
    for(int i=1;i<=n-1;i++)
    {
    	int u,v;
    	cin>>u>>v;	
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>x[i]>>b[i]>>y[i];
	}
	for(int i=1;i<=m;i++)
	{
		int tmp=a[i]-b[i];
		if((tmp==1||tmp==-1)&&(x==y)&&(x==0))
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			vis[a[i]]=x[i];
			vis[b[i]]=y[i];
			if(x[i])
			{
				mustt[i]==1;
			}
			if(y[i])
			{
				mustt[i]==1;
			}
			for(int j=1;j<=n;j++)
			{
				ifmustt[i]
			}
		       	
		}
	}
    return 0;
}
