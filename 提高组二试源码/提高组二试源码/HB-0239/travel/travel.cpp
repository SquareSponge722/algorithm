#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define max___ 10005
using namespace std;
inline void read(int &a) {
	a=0;
	bool f=0;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		a=(a<<1)+(a<<3)+c-'0';
		c=getchar();
	}
	if(f) a=-a;
}
vector<int>path[max___];
bool b[max___],flag=0;
int n,m,cnt[max___],ans[max___],ans_bj,fa[max___],huan[max___],e,q,bj1=0,bj2=0;
inline void dfs1(int t) {
	b[t]=1;
	ans[ans_bj]=t;
	ans_bj++;
	if(cnt[t]==1) return;
	for(register int i=0; i<(int)path[t].size(); ++i) {
		if(b[path[t][i]])continue;
		dfs1(path[t][i]);
	}
}
inline bool dfs2(int t) {
	huan[e]=t;
	e++;
	b[t]=1;
	for(register int i=0; i<(int)path[t].size(); ++i) {
		if(path[t][i]==fa[t])continue;
		if(b[path[t][i]]) {
			for(q=e-1; q>=0; --q) {
				if(huan[q]==path[t][i])break;
			}
			huan[e]=huan[q];
			return 1;
		}
		fa[path[t][i]]=t;
		if(dfs2(path[t][i])) return 1;
	}
	e--;
	b[t]=0;
	return 0;
}
inline bool dfs3(int t) {
	b[t]=1;
	if(ans[ans_bj]<t&&flag==0) return 0;
	else if(ans[ans_bj]>t) flag=1;
	ans[ans_bj]=t;
	ans_bj++;
	if(cnt[t]==1) return 1;
	for(register int i=0; i<(int)path[t].size(); ++i) {
		if(b[path[t][i]]||(t==bj1&&path[t][i]==bj2)||(t==bj2&&path[t][i]==bj1))continue;
		if(!dfs3(path[t][i])) return 0;
	}
	return 1;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);
	read(m);
	for(register int i=1; i<=m; ++i) {
		int u,v;
		read(u);
		read(v);
		cnt[u]++;
		cnt[v]++;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	for(register int i=1; i<=n; ++i) {
		sort(path[i].begin(),path[i].end());
	}
	cnt[1]++;
	if(m==n-1) {
		dfs1(1);
	} else {
		dfs2(1);
		for(register int i=0; i<=n; ++i) {
			ans[i]=10005;
		}
		for(int i=q; i<e; i++) {
			for(int j=1; j<=n; j++) {
				b[j]=0;
			}
			flag=0;
			ans_bj=0;
			bj1=huan[i];
			bj2=huan[i+1];
			cnt[huan[i]]--;
			cnt[huan[i+1]]--;
			dfs3(1);
			cnt[huan[i]]++;
			cnt[huan[i+1]]++;
		}
	}
	for(register int i=0; i<n; ++i) {
		if(i!=n-1) printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
	return 0;
}
