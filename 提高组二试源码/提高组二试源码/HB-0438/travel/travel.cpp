#include<bits/stdc++.h>
using namespace std;

#define maxn 5000
#define read(x) scanf("%d",&x)

int n,m;
vector<int> a[maxn+5];

vector<int> ans;

void dfs(int x,int fa) {
	ans.push_back(x);
	for(int i=0; i<a[x].size(); i++) {
		int y=a[x][i];
		if(y==fa) continue;
		dfs(y,x);
	}
	return ;
}

bool vis[maxn+5];
int rt=0,rtt=0;

void dfs1(int x,int fa) {
	vis[x]=true;
	for(int i=0; i<a[x].size(); i++) {
		int y=a[x][i];
		if(y==fa) continue;
		if(vis[y]) {
			rt=rtt=y;
			break;
		}
		dfs1(y,x);
		if(rt) break;
	}
	if(!rt) vis[x]=false;
	if(x==rt) rt=0;
	return ;
}

int x1,x2;
bool use[maxn+5];
int flg=false;

void dfs2(int x,int nxt) {
	if(vis[x]&&x>nxt&&flg==1) {
		flg=2;
		return ;
	}
	use[x]=true;
	ans.push_back(x);
	if(x==rtt) {
		for(int i=0; i<a[x].size(); i++) {
			int y=a[x][i];
			if(use[y]) continue;
			if(vis[y]&&2!=flg) {
				flg=1;
			}
			dfs2(y,i==(int)a[x].size()-1?nxt:a[x][i+1]);
		}
		return ;
	}
	for(int i=0; i<a[x].size(); i++) {
		int y=a[x][i];
		if(use[y]) continue;
		else dfs2(y,i==a[x].size()-1?nxt:a[x][i+1]);
	}
	return ;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	read(n),read(m);
	for(int i=1; i<=m; i++) {
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1; i<=n; i++) sort(a[i].begin(),a[i].end());
	if(m==n-1) {
		dfs(1,0);
		for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
	} else {
		dfs1(1,0);
		dfs2(1,1e9);
		for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
	}

	return 0;
}
