#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,p[maxn],st,en,xx,yy;
bool vis[maxn];
long long f[maxn][3];
string s;
vector<int> path[maxn];
inline int read() {
	int res=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') {
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
inline void dfs(int u) {
	bool ooo=0;
	for(int i=0; i<(int)path[u].size(); ++i) {
		int v=path[u][i];
		if(!vis[v]) {
			vis[v]=1;
			dfs(v);
			if(f[v][0]!=-1&&f[v][1]!=-1)f[u][1]+=min(f[v][0],f[v][1]);
			else if(f[v][1]!=-1)f[u][1]+=f[v][1];
			else f[u][1]+=f[v][0];
			if(f[v][1]==-1)ooo=1;
			f[u][0]+=f[v][1];
		}
	}
	f[u][1]+=p[u];
	if(ooo)f[u][0]=-1;
	if(u==en){
		if(yy==1)f[u][0]=-1;
		else f[u][1]=-1;
	}
	//cout<<u<<" "<<f[u][1]<<" "<<f[u][0]<<endl;
	return;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	cin>>s;
	for(int i=1; i<=n; ++i)scanf("%d",&p[i]);
	int aa,bb;
	for(int i=1; i<n; ++i) {
		scanf("%d%d",&aa,&bb);
		path[aa].push_back(bb);
		path[bb].push_back(aa);
	}
	for(int i=1; i<=m; ++i) {
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		st=read();
		xx=read();
		en=read();
		yy=read();
		bool ok=0;
		if(xx==yy){
			for(int i=0;i<(int)path[st].size();++i){
				if(path[st][i]==en){
					ok=1;
					break;
				}
			}
		}
		if(ok){
			printf("-1\n");
			continue;
		}
		vis[st]=1;
		dfs(st);
		printf("%lld\n",f[st][xx]);
	}
}
