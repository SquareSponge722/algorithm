#include<cstdio>
#include<algorithm>
#include<iostream>
#define int long long 
using namespace std;
const int maxn=100000+100;
int n,Min=99999999,o=0;
int min(int a ,int b){if(a>b) return b; else return a;}
int max(int a,int b){if(a>b) return a; else return b;}
int map[maxn]={0};
int dis[maxn]={0};
int Ans=0,Flag=0;
void dfs(int l,int r,int ans)
{
	if(l>r||r<l){
		return;
	}
	int MIN=99999999,flag;
	for(int i=l;i<=r;i++)
	{
		if(MIN>map[i])
		{
			MIN=map[i];
			flag=i;
		}
	}
	Ans+=map[flag]-ans;	
	dfs(flag+1,r,map[flag]);
	dfs(l,flag-1,map[flag]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&map[i]);
		if(map[i]<Min)
		{
			Min=map[i];
			o=i;
		}
	}
	dfs(1,n,0);
	printf("%lld",Ans);
	return 0;
}

	