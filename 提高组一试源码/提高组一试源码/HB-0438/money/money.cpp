#include<bits/stdc++.h>
using namespace std;

#define maxn 100
#define maxa 25000
#define read(x) scanf("%d",&x)

int n;
int a[maxn+5];

bool canuse[maxa*2+5];

int s=1,ss[maxa*2+5];

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	read(T);
	while(T--) {
		memset(canuse,0,sizeof(canuse));
		s=1;
		
		read(n);
		for(int i=1; i<=n; i++) read(a[i]);

		sort(a+1,a+n+1);
		canuse[0]=true;
		
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(!canuse[a[i]]) ans++;
			else continue;
			for(int tt=1; tt<=s; tt++) {
				int j=ss[tt];
				if(!canuse[j]) continue;
				int t=(a[n]-j)/a[i];
				for(int k=1; k<=t; k++) {
					int x=j+k*a[i];
					if(canuse[x]) continue;
					canuse[x]=true;
					ss[++s]=x;
				}
			}
			
		}

		printf("%d\n",ans);
	}

	return 0;
}
