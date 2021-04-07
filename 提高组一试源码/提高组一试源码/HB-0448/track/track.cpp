#include <bits/stdc++.h>
using namespace std;
struct node {
	int v,l;
} f;
int n,m,sum,ans,ans1[50010],tot;
bool fw[50010];
vector<node>a[50010];
void dfs(int i) {
	fw[i]=1;
	int maxx=a[i].size();
	if(sum!=0&&maxx==1) {
		ans=max(ans,sum);
		return;
	}
	for(int j=0; j<maxx; j++) {
		if(!fw[a[i][j].v]) {
			sum+=a[i][j].l;
			dfs(a[i][j].v);
			fw[a[i][j].v]=0;
			sum-=a[i][j].l;
		}
	}
	return;
}
void dfs1(int i,int x) {
	if(x==0)return;
	fw[i]=1;
	for(int j=i+1; j<=n; j++) {
		sum=a[i][0].l+a[j][0].l;
		fw[j]=1;
		ans1[tot]=min(sum,ans1[tot]);
		int x1=i;
		while(fw[x1])x1++;
		fw[j]=1;
		dfs1(x1,x-1);
		fw[j]=0;
		if(i==2)tot++;
	}
	return;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	if(m==1) {
		for(int i=1; i<n; i++) {
			int x,y,z;
			cin>>x>>y>>z;
			f.v=y,f.l=z;
			a[x].push_back(f);
			f.v=x;
			a[y].push_back(f);
		}
		for(int i=1; i<=n; i++) {
			if(a[i].size()==1)dfs(i);
		}
		cout<<ans;
	} else {
		for(int i=1; i<n; i++) {
			int x,y,z;
			cin>>x>>y>>z;
			f.v=y,f.l=z;
			a[x].push_back(f);
			f.v=x;
			a[y].push_back(f);
		}
		for(int i=1; i<=n; i++) {
			ans1[tot]=99999;
		}
		dfs1(2,m);
		for(int i=0; i<tot; i++) {
			ans=max(ans,ans1[i]);
		}
		cout<<ans;
	}
	return 0;
}
