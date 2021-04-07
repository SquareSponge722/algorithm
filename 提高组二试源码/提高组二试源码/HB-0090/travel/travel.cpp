#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int f[50009];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int a[50009];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		f[i]=i;
	}
	for(int i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		int fx=find(f[x]);
		int fy=find(f[y]);
		if(fx<fy){
			f[fx]=fy;
			a[x]=x;
			a[y]=f[y];
		}
		else if(fx>fy){
			f[fy]=fx;
			a[x]=f[x];
			a[y]=y;
		}
	}
	a[1]=1;
	for(int i=1; i<=n; i++){
		cout<<a[i]<<" ";
	}
}
