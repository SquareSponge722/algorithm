#include<bits/stdc++.h>
using namespace std;
const long long MAXN=50000;
inline char nc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
long long read() {
	long long x=0;
	char c=nc();
	while(!isdigit(c))c=nc();
	while(isdigit(c))x=x*10+c-48,c=nc();
	return x;
}
long long a[MAXN],cnt;
bool f[MAXN];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.ans","w",stdout);
	long long T=read();
	long long n;
	bool ok=false;
	while(T--) {
		memset(f,0,sizeof(f));
		cnt=0;
		ok=false;
		n=read();
		for(long long i=1; i<=n; i++) {
			a[i]=read();
			if(a[i]==1)ok=true;
		}
		if(ok) {
			puts("1");
			continue;
		}
		f[0]=true;
		sort(a+1,a+n+1);
		for(long long i=1; i<=n; i++) {
			if(f[a[i]])continue;
			cnt++;
			for(long long j=0; j+a[i]<=a[n]; j++)
				if(f[j])f[j+a[i]]=true;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
