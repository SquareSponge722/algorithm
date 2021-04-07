#include<bits/stdc++.h>
using namespace std;
int n,t,cnt,prime[25005],a[105],num_zhi,num_he;
bool noprime[25005],flag;
inline void euler_sieve() {
	noprime[1]=1;
	for(register int i=2; i<=25000; i++) {
		if(!noprime[i]) {
			prime[++cnt]=i;
		}
		for(register int j=1; j<=cnt&&i*prime[j]<=25000; j++) {
			noprime[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
}
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
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	euler_sieve();
	t=read();
	while(t--) {
		n=read();
		flag=1,num_zhi=0,num_he=0;
		for(register int i=1; i<=n; i++) {
			a[i]=read();
			if(noprime[a[i]]) {
				flag=0;
				num_he++;
			} else {
				num_zhi++;
			}
		}
		if(flag) {
			printf("%d\n",n);
			continue;
		}
		printf("%d\n",num_zhi);
	}
	return 0;
}
