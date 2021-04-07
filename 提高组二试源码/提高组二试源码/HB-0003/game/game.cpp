#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	int out,g=0,o;
	int t;
	int suma=0;
	int sumb=0;
	int s,u;

	int sumz=1,summ=1;
	int q;
	if(n<=m) {
		t=n;
		n=m;
		m=t;
	}
	int i,j;
	int p;
	p=n;
	q=m+n;
	int x=p,y=q;
	for(p=n; 1<=p; p--) {
		x=p;
		y=q;
		for(i=1; i<=n; i++) {
			sumz=sumz*y;
			y--;
		}

		for(j=1; j<=n; j++) {
			summ=summ*x;
			x--;
		}
		s=sumz/summ;
		suma=suma+s;
		q--;
	}
	for(q=m+n; n+1<=q; q--) {
		x=p;
		y=q;
		for(i=1; i<=n; i++) {
			sumz=sumz*y;
			y--;
		}

		for(j=1; j<=n; j++) {
			summ=summ*x;
			x--;
		}
		u=sumz/summ;
		sumb=sumb+u;
	}
	g=suma+sumb;

	o=1000000000+7;
	out=g%o;
	cout<<out;
	return 0;
}

