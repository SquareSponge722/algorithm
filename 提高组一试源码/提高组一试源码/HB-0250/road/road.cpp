#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define N 1000000

using namespace std;

long long n,star=INT_MAX,sta,a[N];
long long ans;
//priority_queue<int, vector<int>, greater<int> >q;//Ð¡ÔÚÇ° 
void dfs(int x,int l,int r,int sp)
{
	if(x-l>0){
		int u=INT_MAX,ne;
		for(int i=l;i<=x-1;i++){
			if(u>a[i]){
				u=a[i];
				ne=i;
			}
		}
		dfs(ne,l,x-1,a[x]);
	}
	if(r-x>0){
		int h=INT_MAX,ne;
		for(int i=x+1;i<=r;i++){
			if(h>a[i]){
				h=a[i];
				ne=i;
			}
		}
		dfs(ne,x+1,r,a[x]);
	}
	ans+=a[x]-sp;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(star>a[i]){
			star=a[i];
			sta=i;
		}
	}
	dfs(sta,1,n,0);
	printf("%d",ans);
	return 0;
}
/*
6
4 3 2 5 3 5
*/
