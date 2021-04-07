#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 50005
using namespace std;
int n,m,h[N],cnt,dis[N],ans;
struct edge{
	int to,next,w;
}e[N<<1];
bool vis[N],inq[N];
queue<int> q;

inline void add(const int &u,const int &v,const int &w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt;
}

void spfa(int s){
	dis[s]=0;
	q.push(s);
	inq[s]=1;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();inq[u]=0;
		for(int i=h[u],v;i;i=e[i].next){
			v=e[i].to;
			if(dis[v]<dis[u]+e[i].w&&!vis[v]){
				dis[v]=dis[u]+e[i].w;
				ans=max(ans,dis[v]);
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
					vis[v]=1;
				}
			}
		}
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=n-1;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=n;i++)
		{	memset(vis,0,sizeof vis);
			memset(dis,0,sizeof dis);
			spfa(i);
		}
	printf("%d\n",ans);
	return 0;	
}
