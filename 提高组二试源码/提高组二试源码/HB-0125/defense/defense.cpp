#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
string s;
int p[100010];
int a,x,b,y;
int bb[100010];
int minn=0;

struct node{
	int xx,yy;
}q[100010];


void dfs(int xx,int curr)
{
	if( curr > minn ) return;
	if( xx >= 3 )
	{
		if( bb[xx-2] == 0 && bb[xx-1] == 0 )
		{
			return;
		}
	}
	
	if( xx == n+1 )
	{
		minn=min(minn,curr);
		return;
	}
	
	if( xx == a && x == 1 )
	{
		bb[xx]=1;
		dfs(xx+1,curr+p[xx]);
		bb[xx]=0;
	} 
	
	if( xx == a && x == 0 )
	{
		if( bb[xx-1] == 0 && xx-1 >= 1 ) return;
		bb[xx]=0;
		dfs(xx+1,curr);
	}
	
	if( xx == b && y == 1 )
	{
		bb[xx]=1;
		dfs(xx+1,curr+p[xx]);
		bb[xx]=0;
	} 
	
	if( xx == b && y == 0 )
	{
		if( bb[xx-1] == 0 && xx-1 >= 1 ) return;
		bb[xx]=0;
		dfs(xx+1,curr);
	} 
	
	if( xx != a && xx != b )
	{
		bb[xx]=1;
		dfs(xx+1,curr+p[xx]);
		bb[xx]=0;
		dfs(xx+1,curr);
	}
}

int main()
{
    freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	
	for(int i=1;i<=n;i++) cin>>p[i];
	
	for(int i=1;i<=n-1;i++) cin>>q[i].xx>>q[i].yy;
	
	while( m-- )
	{
		cin>>a>>x>>b>>y;
			
		int curr=0;
		if( x == 0 && y == 0 && ( a == b-1 || b == a-1 ) )
		{
			cout<<-1<<endl;
		}
		else
		{
			minn=10000000;
			memset(bb,0,sizeof(bb));
			dfs(1,0);
			cout<<minn<<endl;
		}
	}
	return 0;
}
