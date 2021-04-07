//road
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
int n,mind=10010;
long long tot=0,ans=0;
int d[100010];

void dfs(int l,int r)
{
	if(l>r) return ;
	if(l==r) { ans+=d[l]; return ; }
	int mini=10010;
	FOR(i,l,r) mini=min(mini,d[i]);
	FOR(i,l,r) d[i]-=mini;
	ans+=mini;
	int s=0;
	bool flag=0;
	FOR(i,l,r+1)
	{
		if(d[i])
		{
			s++;
			if(!flag) flag=1;
		}
		else {
			flag=0;
//			cout<<l<<' '<<r<<' '<<(i-s)<<' '<<(i-1)<<' '<<ans<<endl;
			dfs(i-s,i-1);
			s=0;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	FOR(i,1,n) cin>>d[i];
	dfs(1,n);
	cout<<ans;
	return 0;
}
/*
6
4 3 2 5 3 5
*/
