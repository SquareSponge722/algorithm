#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 50010
#define inf 0x3f3f3f3f

struct edge
{
	int next;
	int to;
	int w;
} e[N<<1];
int head[N<<1];
int dis[N],vis[N];
int n,m,cnt;

void add(int a,int b,int l){
	e[++cnt].to=b;
	e[cnt].w=l;
	e[cnt].next=head[a];
	head[a]=cnt;
}
void spfa(int s){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++) dis[i]=-inf;
	vis[s]=1;dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();vis[k]=0;
		for(int i=head[k];i;i=e[i].next){
			int temp=dis[k]+e[i].w;
			int v=e[i].to;
			if(dis[k]>inf && dis[v]<temp){
				dis[v]=temp;
				if(!vis[v])
					q.push(v),vis[v]=1;
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b,l;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&l);
		add(a,b,l);add(b,a,l);
	}
	spfa(1);
	int ans=inf;
	for(int i=2;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=min(ans,dis[i]+dis[j]);
		}
	}
	cout<<ans;
	return 0;
}
