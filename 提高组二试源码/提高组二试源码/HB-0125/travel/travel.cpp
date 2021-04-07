#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int f[5010];
int d[5010];
bool b[5010];
int dis[5010][5010];
int dis2[5010][5010];
int s[5010];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		dis[x][y]=dis[y][x]=1;
		s[x]++;s[y]++;
		dis2[x][s[x]]=y;
		dis2[y][s[y]]=x;
	}
	
	d[1]=1;
	int t=1;
	int num=1;
	b[1]=true;
	while( t <= n )
	{
		int u=1;
		for(int i=2;i<=n;i++)
		{
			if( b[i] == true ) continue;
			
			if( dis[num][i] )
			{
				d[t+1]=i;
				num=i;
				b[i]=true;
				u=0;
				break;
			}
		}
		
		if( u == 1 )
		{
			for(int i=t;i>=1;i--)
			{
				int xx=0;
				for(int j=1;j<=s[d[i]];j++)
				{
					int p=dis2[d[i]][j];
					if( b[p] == false )
					{
						if( xx == 0 ) xx=p;
						else xx=min(xx,p);
					}
				}
				if( xx == 0 ) continue;
				
			    d[t+1]=xx;
			    num=xx;
			  	b[xx]=true;
			    u=0;
			    break;
				if( u == 0 ) break;
			}
		}
		t++;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
