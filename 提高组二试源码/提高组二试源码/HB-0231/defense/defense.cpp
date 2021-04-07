#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n,m;
int x,y;
char tp;
int tt;
int a[maxn];
int d[maxn];
int js,os;
int c,z;
int k1,k2;
int dep[maxn];
vector<int> g[maxn];
int kk1,kk2;

void mian1() {
	for (int i=1; i<=m; i++) {
		scanf("%d %d %d %d",&x,&y,&c,&z);
		if((y==0&&z==0)||(y==1&&z==1)) {
			if((x%2)!=(c%2)) {
				printf("-1\n");
				continue;
			} else {
				if(y) {
					if(x%2)printf("%d\n",js);
					else printf("%d\n",os);
					continue;
				} else {
					if(!(x%2))printf("%d\n",js);
					else printf("%d\n",os);
					continue;
				}

			}
		} else if((y==1&&z==0)||(y==0&&z==1)) {
			if((x%2)==(c%2)) {
				printf("-1\n");
				continue;
			} else {
				if(y) {
					if(x%2)printf("%d\n",js);
					else printf("%d\n",os);
					continue;
				} else {
					if(c%2)printf("%d\n",js);
					else printf("%d\n",os);
					continue;
				}

			}
		}
	}
}

void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	if(dep[u]%2)kk1+=a[u];
	else kk2+=a[u];
	for (int i=0; i<g[u].size(); i++) {
		if(g[u][i]==fa)continue;
		else dfs(g[u][i],u);
	}
}


int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>tp>>tt;
	for (int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(i%2)js+=a[i];
		else os+=a[i];
	}
	for (int i=1; i<=n-1; i++) {
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(tp=='A') {
		mian1();
		return 0;
	}
	dfs(1,0);
	for (int i=1; i<=m; i++) {
		scanf("%d %d %d %d",&x,&y,&c,&z);
		if((dep[c]%2)&&z==0) {
			printf("-1\n");
			continue;
		}
		if((dep[c]%2==0)&&z==1) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",kk1);
		continue;
	}



	return 0;
}
