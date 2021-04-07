#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s*w;
}
int n,a[110],T,ans;
bool b[10000010],c[10000010];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--) {
		for(int i=1; i<=a[n]; i++)
			b[i]=c[i]=0;
		n=read();
		if(n==2) {
			scanf("%d%d",&a[1],&a[2]);
			if(a[1]%a[2]==0||a[2]%a[1]==0)printf("1\n");
			else printf("2\n");
		} else {
			ans=n;
			for(int i=1; i<=n; i++) {
				a[i]=read();
				if(b[a[i]]==1)ans--;
				c[a[i]]=b[a[i]]=1;
			}
			sort(a+1,a+n+1);
			for(int i=1; i<=n; i++)
				for(int j=2; j*a[i]<=a[n]; j++) {
					if(b[a[i]*j]) {
						ans--;
						b[a[i]*j]=0;
					}
					c[a[i]*j]=1;
				}
			for(int i=1; i<=n; i++)
				if(b[a[i]])
					for(int j=a[1]; j<=a[i]; j++)
						if(c[j]==1&&c[a[i]-j]==1) {
							ans--;
							b[a[i]]=0;
							break;
						}
			printf("%d\n",ans);
		}
	}
	return 0;
}
