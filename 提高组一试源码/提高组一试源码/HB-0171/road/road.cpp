#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define rg register

using namespace std;

const int N=100000+10;
int n;
int minv=(1<<30),minn,ans,minvv=(1<<30);
int d[N];
void dfs(int x,int y){
	ans+=d[x];
	for(int i=1;i<=y;i++)d[i]-=d[x];
	y=x-1;
	if(y==0)return;
	minv=1<<30;
	minvv=1<<30;
	for(int i=1;i<=y;i++)
		if(d[i]<minv)minv=d[i],minn=i;
	dfs(minn,y);
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(rg int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i]<minv)minv=minvv=d[i],minn=i;
	}
	dfs(minn,n);
	printf("%d",ans);
	return 0;
	
}
