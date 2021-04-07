#include<bits/stdc++.h>
using namespace std;

int n,m;
struct edge{
	int v,next,head;
}e[200005];


void add(int u,int v,int k) {
	
}


int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;a,b,c;i<=n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	prim();
	return 0;
}
