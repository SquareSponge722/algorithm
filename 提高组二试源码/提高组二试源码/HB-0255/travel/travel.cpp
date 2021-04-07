#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
const int N = 5005;
int read(){
	char ch=getchar();int x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
struct Edge{
	int to,next;
}edge[2*N];
struct Node{
	int x;int y;
}node[N];
int head[2*N+5],n,m,ans[N],tot[N];
queue<int > q;
bool vis[N],devis[N];
bool cmp(Node x,Node y){
	if(x.x==y.x)return x.y<y.y;
	return x.x>y.x;
}
void debug(){
	q.push(1);
	devis[1]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=edge[i].next){
			int v=edge[i].to;
			if(devis[v])continue;
			cout<<u<<"->"<<v<<endl;
			devis[v]=true;
			q.push(v);
		}
	}
	return;
}
void cp(){
	for(int i=1;i<=ans[0];i++){
		if(tot[i]<ans[i]){
			for(i=1;i<=ans[0];i++)
				ans[i]=tot[i];
			return;
		}
	}
}
void dfs(int x){
	if(tot[0]==n){
		cp();
		return;
	}
	for(int i=head[x];~i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])continue;
		tot[++tot[0]]=v;
		vis[v]=true;
		dfs(v);
		dfs(x);
	}
	return;
}
void pro1(){
	int en=0;
	fill(ans,ans+n+1,N);
	ans[0]=n;
	for(int i=1,x,y;i<=m;i++){
		x=read();y=read();
		node[++en].x=x;
		node[en].y=y;
		node[++en].x=y;
		node[en].y=x;
	}
	memset(head,-1,sizeof(head));
	sort(node+1,node+en+1,cmp);
	for(int i=1,x,y;i<=en;i++){
		edge[i].to=node[i].x;
		edge[i].next=head[node[i].y];
		head[node[i].y]=i;
	}
	for(int i=1;i<=n;i++)tot[i]=0;
	tot[0]=1;
	tot[1]=1;
	vis[1]=true;
	dfs(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return;
}
void pro2(){
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	pro1();
	return 0;
}
