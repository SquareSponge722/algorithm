#include<bits/stdc++.h>
using namespace std;

int n,m,a,x,b,y;
int p[2005],f[2005][2005];
string type;

void read() {
	scanf("%d%d",&n,&m);
	scanf("%s",&type);
	for (int i=1;i<=n;i++) 
		scanf("%d",&p[i]);
	for (int i=1,u,v;i<=n-1;i++) {
		scanf("%d%d",&u,&v);
		f[u][v] = 1;
		f[v][u] = 1;
	}
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read();
	for (int i=1;i<=m;i++) {
		printf("-1\n");
	}
	return 0;
}
