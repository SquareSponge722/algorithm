#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 100001
using namespace std;
inline int read(){
	char ch=getchar();
	int ans=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*cf;
}
int n,a[maxn],minx,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	minx=a[1];
	ans=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]<=minx){
			minx=a[i];
		}
		else{
			ans=ans+(a[i]-minx);
			minx=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}

