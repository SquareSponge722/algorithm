#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,x,y,ff,g;
char s[5];
int f[2005][3];
int w[100005];
int dp(int o,int xz){
	if(f[o][xz]!=-1) return f[o][xz];
	if(o+1==a){
		return f[o][xz]=dp(o+1,x)+w[o]*xz;
	}
	else if(o+1==b){
		return f[o][xz]=dp(o+1,y)+w[o]*xz;
	}
	else if(xz==1){
		return f[o][xz]=min(dp(o+1,0),dp(o+1,1))+w[o]*xz;
	}
	if(xz==0){
		return f[o][xz]=dp(o+1,1)+w[o]*xz;
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	if(s[0]=='A') {
		for(int i=1; i<=n; i++) {
			scanf("%d",&w[i]);
		}
		for(int i=1; i<n; i++) {
			scanf("%d%d",&ff,&g);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(s[1]=='2'&&x==0&&y==0) {
				printf("-1\n");
				continue;
			} else if(s[1]=='1'){
				memset(f,-1,sizeof(f));
				printf("%d\n",dp(1,1));
			}	
			else {
				memset(f,-1,sizeof(f));
				printf("%d\n",min(dp(1,1),dp(1,0)));
			}
		}
	}
	else for(int i=1;i<=m;i++) printf("-1\n");
	return 0;
}
