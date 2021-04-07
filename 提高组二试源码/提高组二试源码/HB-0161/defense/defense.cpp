#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
 
vector<int> mp[100005];

int book[100005];
int cost[100005];



long long min(long long aa, long long bb)
{
	if(aa==-1 ||bb==-1)
	{
		return aa==-1?bb:aa;
	}
	else return aa>bb?aa:bb;
}

int x,a,y,b;

long long dfs(int city, long long costt)
{
	if(city == x)
	{
		book[city] = a;
		if(a==0 && book[city]-1==0) return -1;
		return dfs(city+1, costt+ a*cost[city]);
	}
	else if(city==y)
	{
		book[city] = b;
		if(b==0 && book[city]-1==0) return -1;
		return dfs(city+1, costt+ b*cost[city]);
	}
	else
	{
		long long r = -1;
		if(book[city-1]==0)
		{
			book[city] = 1;
			return dfs(city+1, costt+cost[city]);
		}
		else
		{
			book[city] = 1;
			r = min(r,dfs(city+1, costt+cost[city]));
			book[city] = 0;
			r = min(r,dfs(city+1, costt));
		}
		return r;
	}
}

int solve()
{
	if(x > y)
	{
		swap(x,y);
		swap(a,b);
	}
	if(x==y-1 && a==0 && b==0)
	{
		printf("-1\n");
		return 0;
	}
	book[0]=1;
	printf("%lld\n",dfs(1,0));
}

int main()
{
	freopen("defense1.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	string type;
	cin>>type;
	if(type[0]=='A' || true)
	{
		for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
		for(int i=1;i<n;i++)
		{
			int ta,tb;
			scanf("%d%d",&ta,&tb);
			mp[ta].push_back(tb);
			mp[tb].push_back(ta);
		}
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&x,&a,&y,&b);
			solve();
		}
	}
	
	
	return 0;
}
