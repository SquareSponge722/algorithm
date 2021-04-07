#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int d[N],n;
#define ll long long

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",d+i);
	ll ans=0;
	d[0]=0;
	for(int i=1;i<=n;i++){
		if(d[i]>d[i-1]) ans+=(d[i]-d[i-1]);
		else continue;
	}
	printf("%lld",ans);
	return 0;
}
