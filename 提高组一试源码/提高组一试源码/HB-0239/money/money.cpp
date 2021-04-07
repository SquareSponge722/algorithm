#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline void read(int &a) {
	a=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		a=(a<<1)+(a<<3)+c-'0';
		c=getchar();
	}
}
inline int gcd(int a,int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}
inline void exgcd(int a,int b,int &x,int &y) {
	if(b==0) {
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	swap(x,y);
	y=y-(a/b)*x;
	return;
}
int tttttttt;
int n,m;
int a[105],c[105];
bool b[105];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(tttttttt);
	for(register int iiiiiiii=1; iiiiiiii<=tttttttt; ++iiiiiiii) {
		read(n);
		for(register int i=1; i<=n; ++i) {
			read(a[i]);
			b[i]=0;
		}
		sort(a+1,a+n+1);
		for(register int i=1; i<=n; ++i) {
			for(register int j=i+1; j<=n; ++j) {
				int GCD=gcd(a[i],a[j]);
				if(a[j]%a[i]==0) {
					b[j]=1;
					continue;
				}
				for(register int k=j+1; k<=n; ++k) {
					if(b[k])continue;
					if(a[k]%GCD!=0)continue;
					int x,y;
					exgcd(a[i],a[j],x,y);
					x*=a[k]/GCD;
					y*=a[k]/GCD;
					if(x>=0&&y>=0) {
						b[k]=1;
						continue;
					}
					int aa=a[i]/GCD;
					int bb=a[j]/GCD;
					if((y<0&&y+(x/bb)*aa>=0)||(x<0&&x+(y/aa)*bb>=0)) {
						b[k]=1;
					}
				}
			}
		}
		m=0;
		for(int i=1; i<=n; i++) {
			if(!b[i]) {
				m++;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
