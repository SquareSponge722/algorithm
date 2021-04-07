#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,n) for(int i=1;i<=n;i++)
using namespace std;
int a[100005],ans=0,n,len=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,n){
		scanf("%d",a+i);
		if(i==n)ans+=a[i];
		ans+=(a[i]-a[i-1])>(a[i-1]-a[i])?(a[i]-a[i-1]):(a[i-1]-a[i]);
	}
	cout<<ans/2;
	return 0;
}
