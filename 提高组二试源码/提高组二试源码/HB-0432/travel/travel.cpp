#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,u,v,x=0,j=1;
	cin>>n>>m;
	int a[n+1][n+1],b[n+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u][v]++;
		a[v][u]++;
	}
    cout<<1<<" ";
    for(int i=1;i<=n+1;i++)
		{
			i=j;
			b[i]++;
		for(j=1;j<=n+1;j++)
		{
	        if(a[i][j]!=0)
			{
				if(b[j]!=1)
				{
					cout<<j<<" ";
					i=j;
					x++;
					break;
				}
			}
	    }
	    if(x==(n-1))break;
	}
	return 0;
}
