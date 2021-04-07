#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define N 500001
#define LL long long
#define inf 2147483647
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
struct graph{int to,next;LL val;}e[N*2];
LL head[N],cnt,dis[N],vis[N];
int n,m,ans[1000001],num;
inline void addedge(int u,int v,LL w){
	e[++cnt].next=head[u],head[u]=cnt;
	e[cnt].to=v,e[cnt].val=w;
}
inline void spfa(int src){
	queue<int>q;
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	vis[src]=1,dis[src]=0,q.push(src);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				if(!vis[v])vis[v]=1,q.push(v);
			}
		}
	}
}
inline bool cmp(LL x,LL y){return x>y;}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();LL w=read();
		addedge(u,v,w),addedge(v,u,w);
	}
	for(int i=1;i<=n;i++){
		spfa(i);
		for(int j=1;j<=n;j++)
			ans[++num]=dis[j];
	}
	sort(ans+1,ans+num+1,cmp);
	printf("%lld",ans[m*2]);
	return 0;
}
