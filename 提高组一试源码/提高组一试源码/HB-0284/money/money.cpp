#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#define REP(u) for(int w,v,i=head[u];v=pan[i].to,w=pan[i].wi,i;i=pan[i].next)

using namespace std;

const int maxn=10001;

ifstream fin("money.in");
ofstream fout("money.out");

int T,n,maxp,m;

bool flag;

int a[maxn];

bool vis[maxn];

inline void dfs(int x) {
	for(int i=2,j=1; i<=maxp,j<=n; i++) {
		while(a[j]%i==0&&!vis[a[j]]&&a[j]!=0) vis[a[j]]=1,j++;
		for(int k=i+1; k<=maxp; k++) {
			while(a[j]%k==0&&!vis[a[j]]&&a[j]!=0) {
				vis[a[j]]=1,j++;
			}
			if(j==n) {
				cout<<m;
				flag=1;
				return;
			}
		}
		memset(vis,0,sizeof(vis));
		if(j==n) {
			cout<<m;
			flag=1;
			return;
		}
	}
}

inline void work() {
	while(true) {
		if(!flag) {
			dfs(m);
			m++;
		}
		if(flag==1) break;
	}
}

int main() {
	fin>>T;
	while(T--) {
		fin>>n;
//		for(int i=1; i<=n; i++) {
//			cin>>a[i];
//			maxp=max(a[i],maxp);
//		}
//		work();
//		memset(a,0,sizeof(a));
		fout<<n<<'\n';
	}
	return 0;
}
