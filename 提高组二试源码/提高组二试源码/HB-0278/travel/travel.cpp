#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=5005;
const int maxm=10005;

int n,m,sum,s,t;
int cnt[maxn];
int a[maxn],b[maxn],fat[maxn];
int g[maxn][maxn];
bool used[maxn];

void dfs1(int u,int fa) {
	int num=cnt[u];
	a[++sum]=u;used[u]=true;
	for(int i=1;i<=num;i++) {
		int v=g[u][i];
		if(v==fa) continue;
		if(used[v]) {
			s=u,t=v;
		} else {
			fat[v]=u;
			dfs1(v,u);
		}
	}
	return ;
}

void dfs2(int u,int fa,int x,int y) {
	int num=cnt[u];
	b[++sum]=u;
	for(int i=1;i<=num;i++) {
		int v=g[u][i];
		if(v==fa) continue;
		if((u==x && v==y)||(u==y && v==x)) continue;
		dfs2(v,u,x,y);
	}
}

bool cmp() {
	for(int i=1;i<=n;i++) {
		if(a[i]<b[i]) return true;
		if(a[i]>b[i]) return false;
	}
	return true;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		++cnt[u];g[u][cnt[u]]=v;
		++cnt[v];g[v][cnt[v]]=u;
	}
	for(int i=1;i<=n;i++) sort(g[i]+1,g[i]+cnt[i]+1);
	if(m==n-1) {
		dfs1(1,1);
		b[1]=2;
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
