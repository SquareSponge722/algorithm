#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 6001
#define ll long long
using namespace std;
int read(){
	char ch;
	int ans=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*cf;
}
ll n,m,anscnt,ans[maxn],mapa[5001][5001];
bool vis[maxn];
void dfs(int now,int fa){
	if(!vis[now]){
		vis[now]=1;
		printf("%d ",now);
	}
	for(int i=1;i<=n;i++){
		if(mapa[now][i] && i!=fa){
			dfs(i,now);
		}
	}
}
void dfs2(int now){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			tmp++;
		}
	}
	if(tmp==n){
		for(int i=1;i<=anscnt;i++){
			printf("%d ",ans[i]);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(mapa[now][i]){
			vis[i]=1;
			anscnt++;
			ans[anscnt]=i;
			dfs2(i);
			vis[i]=0;
			anscnt--;
			ans[anscnt]=0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		mapa[u][v]=1;
		mapa[v][u]=1;
	}
	if(m==n-1){
		dfs(1,0);
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			printf("%d ",i);
		}
	}
	return 0;
}
