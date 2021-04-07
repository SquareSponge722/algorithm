#include<bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long
ll ans=0;
int n,m,a,b;
int x,y;
int cs[2],p[N];

void read(){
	char ch=getchar();
	while(!isdigit(ch)&&!isalpha(ch)) ch=getchar();
	cs[0]=ch-'A';
	scanf("%d",cs+1);
}

void dfs1(int o,int arm){
	if(arm) ans+=p[o];
	if(o==1){
		return;
	}
	dfs1(o-1,1-arm);
}

void dfs2(int o,int arm){
	if(arm) ans+=p[o];
	if(o==n){
		return;
	}
	dfs2(o+1,1-arm);
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	read();
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	if(cs[0]==0){
		if(cs[1]==2){
			for(int i=1,u,v;i<=n-1;i++)
				scanf("%d%d",&u,&v);
			for(int i=1;i<=m;i++){
				ans=0;
				scanf("%d%d%d%d",&a,&x,&b,&y);
				if(x==0&&y==0){
					puts("-1");
					continue;
				}
				if(a<b){
					dfs1(a,x);
					dfs2(b,y);
				}
				else{
					dfs1(b,y);
					dfs2(a,x);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
