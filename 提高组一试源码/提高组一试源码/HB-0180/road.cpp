#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INF 99999999
#include<algorithm>
using namespace std;
int n,a[100010],ans;
void work(int l,int r,int p){
	if(r<l) return;
	int minn=INF,u;
	for(int i=l;i<=r;i++) if(minn>a[i]-p) minn=a[i]-p, u=i;
	if(minn==0){work(l,u-1,p); work(u+1,r,p);}
	else{
		ans+=minn;
		work(l,u-1,p+minn); work(u+1,r,p+minn);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	work(1,n,0);
	printf("%d\n",ans);
}
/*
6
4 3 2 5 3 5
*/
