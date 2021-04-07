#include<bits/stdc++.h>
using namespace std;
int vis[5050],dis[5050],head[5050];
int n,m;
int k=0;
typedef pair<int,int> pp;
priority_queue<pp,vector<pp>,greater<pp> > pq;
int sum=0;
struct edge{
	int v,w,next;
}e[40040];

void add(int u,int v,int w){
	e[++k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}

void prim(int s){
	dis[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int d=pq.top().first,u=pq.top().second;
		pq.pop();
		if(d!=0)
		cout<<d<<" ";
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			if(dis[e[i].v]>e[i].w){
				dis[e[i].v]=e[i].w;
				pq.push(make_pair(dis[e[i].v],e[i].v));
			}
		}
	}
}

int main(){
	ifstream cin("travel.in");
	ofstream cout("travel.out");
	ios::sync_with_stdio(false);
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b,b);
		add(b,a,a);
	}
	cout<<1<<" ";
	prim(1);

	return 0;
}
