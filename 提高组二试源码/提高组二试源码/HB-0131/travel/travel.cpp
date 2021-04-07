#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[5001][5001];
int t=1,f[5001],g[5001],hash[5001][5001];

void dfs(int k) {
	int mi=9999999,find=0,dd;
	t++;
	if(t>=n+1)return;
	for(int i=1; i<=n; i++)
		if(a[f[k-1]][i]==1&&hash[f[k-1]][i]==0) find=1;
	if(find==0) return;

	for(int i=1; i<=n; i++)
		if(a[f[k-1]][i]==1&&hash[f[k-1]][i]==0&&i<mi) {
			mi=i;dd=0;
			for(int j=1; j<=t; j++)
			if(mi==g[j]){
				dd=1;
				hash[f[k-1]][mi]=hash[mi][f[k-1]]=1;
			}
			if(dd==1){
				mi=9999999;
				continue;
			}
			else {
				f[k]=g[t]=mi;
				hash[f[k-1]][mi]=hash[mi][f[k-1]]=1;
			}
			dfs(k+1);
			f[k]=0;
			mi=9999999;
		}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int x,y;
	for(int i=1; i<=m; i++) {
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	f[1]=1,g[1]=1;
	dfs(2);
	for(int i=1; i<=n; i++)
		cout<<g[i]<<" ";
	return 0;
}
