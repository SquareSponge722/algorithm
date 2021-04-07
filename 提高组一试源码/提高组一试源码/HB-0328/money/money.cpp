#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
int a[104],n,T;
bool f[30000000];
int gcd(int x,int y) {
	if(y==0)return x;
	return gcd(y,x%y);
}
bool check(int x,int y) {
	for(int i=1; i<=a[1]*a[2]-a[1]-a[2]+min(a[1],a[2]); i++) {
		if(!f[i]&&(f[i-x]|f[i-y]))return 0;
		if(f[i]&&!(f[i-1]|f[i-y]))return 0;
	}
	return 1;
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		if(n==2) {
			//if(a[1]*a[2]-a[1]-a[2]==)

			if(gcd(a[1],a[2])!=1) {
				cout<<1<<endl;
				continue;
			} else {
				cout<<2<<endl;
				continue;
			}
			/*	for(int i=1; i<=max(a[1],a[2]); i++)
					for(int j=i+1; j<=max(a[1],a[2]); j++) {
						if(i*j-i-j!=a[1]*a[2]-a[1]-a[2])continue;
						if(check(i,j))
						}*/
		}
		/*	f[a[1]]=f[a[2]]=1;
			for(int i=min(a[1],a[2]);; i++) {
				f[i]=f[i]|f[i-a[1]],f[i]=f[i]|f[i]-a[2];

				bool ok=1;
				for(int j=i-min(a[1],a[2]); j<=n; j++) {
					if(!f[i])ok=0;
				}
				if(ok)break;
			}*/
		/*	else {
				for(int i=1; i<=n; i++)
					for(int j=i+1; j<=n; j++) {
						int gc=gcd(a[i],a[j]);
						if(gc!=1)
				}*/
	}
}

