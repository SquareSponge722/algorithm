# include <csdio>
# include <cstring>
# include <iostream>
using namespace std;
# define N 100005
struct Edge{
	int next;
	int to;
} e[N*2];
int head[N];
char k[2];
int aa[N];
int de[N][2];
int s;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",k);
	scanf("%d",&s);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d",&aa[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		e[i]=(Edge){head[u],v};
		head[u]=i;
		e[i+n-1]=(Edge){head[v],u};
		head[v]=i+n-1;
	}
	int a,x,b,y;
	int ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(y==1){
			ans+=aa[a];
			for(int i=2;i<=n;i++){
				if(i==b){
					dp[i][1]=min(de[i-1][1],dp[i-1][0])+aa[i];
					dp[i][0]=min(de[i-1][1],dp[i-1][0])+aa[i];
				}
				else{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=min(de[i-1][1],dp[i-1][0])+aa[i];
				}
			}
			printf("%d",min(dp[n][0],dp[n][1]));
    	}
	}
	return 0;
}
