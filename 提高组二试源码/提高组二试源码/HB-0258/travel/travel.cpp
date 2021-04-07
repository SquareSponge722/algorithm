#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int oo=0x7fffffff;
int n,m,en=1,cnt=0;
int head[N];
int ans[N];
int vis[N];//false���ߵ��� 
stack<int>q;

struct Edge{
	int to,next,w;
};
Edge edge[N];

void init(){
	memset(ans,0,sizeof(ans));
	memset(head,-1,sizeof(head));
	memset(vis,false,sizeof(vis));			
}


void solve(){
	while(!q.empty( )){
		int u=q.top();
		int minn=oo;
		int id=0;	
		for(int k=head[u];k!=-1;k=edge[k].next){
			int v=edge[k].to;
			int wei=edge[k].w;
			if(wei<minn && vis[v]==0) {
				minn=wei;
				id=v;
			}
		}	
		 if(id==0) q.pop();
		 else if(vis[id]==0){		
		 	q.push(id);	
		 	cnt++;
		 	ans[cnt]=id;	
		 	vis[id]=1;	
		 } 	
		if(cnt==n) return ;
	}	
}		

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();	
	for(int i=1,a,b;i<=m;i++){
		cin>>a>>b;
		edge[en].to=b;		
		edge[en].w=b;//�����Ϊ��ֵ 
		edge[en].next=head[a];		
		head[a]=en++;
		edge[en].to=a;
		edge[en].w=a;//�����Ϊ��ֵ 
		edge[en].next=head[b];		
		head[b]=en++;				
	}
	q.push(1);
	vis[1]=1;
	cnt++;
	ans[cnt]=1;
	solve();
	for(int i=1;i<=cnt;i++){
		printf("%d ",ans[i]);//�л����� 
	}
	return 0;
}
