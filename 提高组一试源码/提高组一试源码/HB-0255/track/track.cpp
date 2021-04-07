#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 50005;
int read(){
	char ch=getchar();int x=0,y=1;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*y;
}
int n,m;
queue<int >q;
struct Edge{
	int w;
	int to,next;
}edge[N*2];
int head[N*2];
int tot[N];
bool vis[N];
void pro1(){
	int en=0,ans=0,point;
	memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++){
		x=read();y=read();z=read();
		edge[++en].to=y;
		edge[en].w=z;
		edge[en].next=head[x];
		head[x]=en;
		edge[++en].to=x;
		edge[en].w=z;
		edge[en].next=head[y];
		head[y]=en;
	}
	q.push(1);
	vis[1]=true;
	while(!q.empty()){
		int u,v;
		u=q.front();
		q.pop();
		for(int i=head[u];~i;i=edge[i].next){
			v=edge[i].to;
			if(!vis[v]){
				tot[v]=tot[u]+edge[i].w;
				if(tot[v]>ans){
					ans=tot[v];
					point=v;
				}
				vis[v]=true;
				q.push(v);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	memset(tot,0,sizeof(tot));
	q.push(point);
	vis[point]=true;
	ans=0;
	while(!q.empty()){
		int u,v;
		u=q.front();
		q.pop();
		for(int i=head[u];~i;i=edge[i].next){
			v=edge[i].to;
			if(!vis[v]){
				tot[v]=tot[u]+edge[i].w;
				if(tot[v]>ans)
					ans=tot[v];
				vis[v]=true;
				q.push(v);
			}
		}
	}
	cout<<ans;
}
int dp[1005][1005];
int qq[N],p[N];
void pro2(){
	for(int i=1,x,y,z;i<n;i++){
		x=read();y=read();z=read();
		p[y]=z;qq[y]=qq[x]+p[y];
	}
	dp[1][1]=0;
	for(int i=2;i<=n;i++){
		dp[i][1]=dp[i-1][1]+p[i];
	}
	for(int j=2;j<=m;j++)
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				dp[k][j]=max(min(dp[i][j-1],qq[k]-qq[i]),dp[k][j]);
	cout<<dp[n][m];
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	if(m==1)pro1();
	else pro2();
}
