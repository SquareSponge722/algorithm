#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(register int i=1; i<=n; i++) {
		a[i]=read();
	}
	for(register int i=1; i<=n; i++) {
		if(a[i+1]<=a[i]) {
			ans+=(a[i]-a[i+1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
