#include <cstdio>

long long mod=1e9+7;

long long qpow(int a, int b) {
	if (b==0) return 1;
	long long d=qpow(a, b>>1);
	d=(d*d)%mod;
	if (b%2==1) d=(d*a)%mod;
	return d;
}

int n, m;
int get(int s, int x, int y) {
	int h=(x-1)*m+y;
	return (s>>(h-1))%2;
}
int pop(int x) {
	if (x==0) return 0;
	return x%2+pop(x>>1);
}

void print(int x) {
	if (x>=2) print(x>>1);
	printf("%d", x%2);
}

int check(int s, int p) {
	int x=n,y=m;
	int r=0;
	for (int i=1;i<=n+m-2;++i) {
		r=(r<<1)+get(s, x, y);
		if ((p>>(i-1))%2==0) x--;
		else y--;
	}r=(r<<1)+get(s, x, y);
	return r;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d", &n, &m);
//	printf("%d %d", n, m);
	if (n==1) printf("%lld", qpow(2, m));
	else if (n==2) printf("%lld", (4*qpow(3, m-1))%mod);
	else if (n==3&&m==3) printf("112");
	else {
	int cnt=0;
	for (int s=0;s<=(1<<(n*m))-1;++s) {
		int flag=0;
	//	print(s); printf("\n");
		for (int i=0;i<=(1<<(n+m-2))-1;++i) {
			if (flag) break;
			if (pop(i)!=m-1) continue;
			for (int j=0;j<=(1<<(n+m-2))-1;++j) {
				if (flag) break;
				if (pop(j)!=m-1) continue;
			//	print(i); printf("  "); print(j); printf("  ");
				if (i>j&&check(s, i)>check(s, j)) flag=1;
			//	print(check(s, i)); printf("  "); print(check(s, j)); printf("  ");
			}
		}if (!flag) cnt++;
	}printf("%d", cnt);
	}
		
	return 0;
}
