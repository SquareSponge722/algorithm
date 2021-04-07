#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int N;
int d[100050];
int ans;
void dfs(int l,int r,int _off);
int main()  {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)  {
		scanf("%d",&d[i]);
	}
	dfs(1,N,0);
	printf("%d",ans);
	return 0;
}
void dfs(int l,int r,int _off)  {
	if(l>r)  return;
	if(l==r)  {
		ans+=d[l]-_off;
		return;
	}
	int minn=0x7f7f7f7f,k;
	for(int i=l;i<=r;i++)  {
		if(d[i]-_off<minn)  {
			minn=d[i]-_off;
			k=i;
		}
	}
	if(!minn)  {
		dfs(l,k-1,_off);
		dfs(k+1,r,_off);
		return;
	}
	ans+=minn;
	dfs(l,k-1,_off+minn);
	dfs(k+1,r,_off+minn);
	return;
}
