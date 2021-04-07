#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define rg register

using namespace std;

const int N=50000+10;
int n,m;
struct node{
	int a,b,l;
}q[N];
int f[N][10001];
int maxv;
int main(){
	
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].l);
		f[q[i].a][q[i].b]=f[q[i].b][q[i].a]=q[i].l;
	}
	for(rg int k=1;k<=n;k++)
		for(rg int i=1;i<=n;i++)
			for(rg int j=1;j<=n;j++)
				if(f[i][k]&&f[k][j])f[i][j]=f[j][i]=f[i][k]+f[k][j];
	for(rg int i=1;i<=n;i++)
		for(rg int j=1;j<=n;j++)
			maxv=max(f[i][j],maxv);
	cout<<maxv;
	return 0;
	
}
