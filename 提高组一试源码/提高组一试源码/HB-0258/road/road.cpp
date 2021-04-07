#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,d[N];
int a[N];
int ans=0;
int minn=10005;
int en=1;
int max1=0;
int tot=0;

void solve(int l,int r){
	int max=0;
	for(int i=l;i<=r;i++){
		if(max<d[i]) max=d[i];
	}
	ans+=max;			
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		minn=min(minn,d[i]);
	} 
	for(int i=1;i<=n;i++){
		if(minn==d[i]) a[en++]=i;
	}
	int l=1,r=a[1];
	solve(l,r);
	for(int i=1;i<=en-1;i++){
		l=a[en]+1,r=a[en];	
		solve(l,r);	
	}
	l=a[en]+1,r=n;
	solve(l,r);	
	printf("%d",ans);
	return 0;	
}


