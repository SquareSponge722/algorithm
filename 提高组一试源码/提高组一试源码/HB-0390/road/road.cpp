#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int a[100005],minn,ans;
long long int read() {
	long long int f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9') {
		f=(f<<3)+(f<<1)+ch-'0';
		ch=getchar();
	}
	return f;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) {
		a[i]=read();
	}
	int f=1,havefind=1;
	minn=1e9;
	while(f) {
		f=0;
		while(!a[havefind]) {
			havefind++;
			if(havefind==n+1)break;
		}
		if(havefind==n+1)break;
		for(int i=havefind; ; i++) {
			if(a[i]==0) {
				ans+=minn;
				for(int j=havefind; j<=i-1; j++)
					a[j]-=minn;
				minn=1e9;
				break;
			} else if(i==n) {
				minn=min(minn,a[i]);
				ans+=minn;
				for(int j=havefind; j<=i; j++)
					a[j]-=minn;
				minn=1e9;
				break;
			} else {
				f=1;
				minn=min(minn,a[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}
