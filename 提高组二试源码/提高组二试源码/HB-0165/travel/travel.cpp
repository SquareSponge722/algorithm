#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 5005;
int n,m,en(0),num[N],ans[N],head[N],cnt=1,js;
struct Edge{
	int nex,to;
}edge[N];
queue<int> q;
int vis[N],inq[N];

void add(int a,int b){
	edge[en].to = b;
	edge[en].nex = head[a];
	head[a] = en++;
}
//
//void dfs(int s){
//	q.push(s);
//	inq[s]=true;
//	int u,v;
//	while(!q.empty() ){
//		u=q.front() ;
//		q.pop() ;
//		inq[u]=false;
//		for(int p=head[u];p!=-1;p=edge[p].nex ){
//			v=edge[p].to;
///*wrong*/	if(!vis[v]) {
//				cnt++;
//				ans[cnt]=min(ans[cnt],num[v]);
//				q.push(v); 
//				inq[v]=true;
//			}
//			dfs(edge[p].nex);
//		}
//	}
//}

void dfs(int s){
	vis[s]=1;
	for(int p=head[1];p!=-1;p=edge[s].nex ){
		js=5005;
		js=min(js,num[p]);
	}
	ans[++cnt] = js;
	vis[s]=0;
	dfs(js);
	if(cnt==n-1){	
		printf("%d ",1);
		for(int i=2;i<=n;i++)
			printf("%d ",ans[i]);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fill(vis,vis+N,0);
	fill(inq,inq+N,0);
	fill(head,head+N,-1);
	for(int i=1;i<=n;i++) num[i]=i;  
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	return 0;
}
