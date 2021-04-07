#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
string ss;
namespace task1
{
	void work()
	{
		
	}
}
namespace task2
{
	int a[100050],f[100050][2];
	int work2(int x,int x1,int y,int y1)
	{
		if(x==y&&!y1&&!x1) return -1; 
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(min(f[i-2][0]+a[i],f[i-2][1]+a[i]),f[i-1][0]+a[i]);
		}
		return min(f[n][1],f[n][0]);
	}
	void work()
	{
		int x,x1,y,y1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++) cin>>x>>y;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>x1>>y>>y1;
			cout<<work2(x,x1,y,y1);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>ss;
	task2::work();
	return 0;
}
