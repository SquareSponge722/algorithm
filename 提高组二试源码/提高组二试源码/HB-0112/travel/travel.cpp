#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

int m,n,a[5001],b[5001],c[5001];
bool pd[5001]={0};

int bfs(int);

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	int i;
	for(int i=1;i<=m;++i)
	cin>>a[i]>>b[i];
	bfs(1);
	cout<<c[i];
	return 0;
}
int bfs(int x)
{
	
	for(int x=1;x<=n;++x)
	{
		
		{
			if(x<=m&&a[x]!=b[x])
			pd[x]=1;
		    if(pd[x]==1&&b[x]<b[x+1])
		    c[x]=b[x];
		    if(pd[x]==1&&b[x]>b[x+1])
		    c[x]=b[x+1];
			if(x==n)
			{
				return c[x];
			}
			else
			bfs(x+1);
		}
	}
}
