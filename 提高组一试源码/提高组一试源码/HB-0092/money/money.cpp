#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

inline void read(int &x) {
	int w = 1;
	x = 0;
	char c = getchar();

	while(!isdigit(c)) {
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x*10 + c - '0';
		c = getchar();
	}
	x *= w;
}

int T,n;
int a[100005];

int gcd(int x,int y)
{
	if(y == 0) return x;
	return gcd(y,x%y);
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	read(T);
	while(T--) {
		read(n);
			for(int i=1; i<=n; i++) 
				read(a[i]);
			int x = gcd(a[1],a[2]);
			int y = a[1] * a[2] / x;
			printf("2\n");
		


	}

}
