#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=5005;
int n,m;
struct Edge{
	int nex,to;
	//bool operator <(const Edge &x){to<x.to;}
}edge[2*M];
int x[N],y[N];
bool vis[N];
int en=0,h[N];
//int num[2*N];

void Ad(int x,int y){
	edge[en].to=y;
	edge[en].nex=h[x];
	h[x]=en++;
}
void dfs(int i){
	printf("%d ",i);
	vis[i]=true;
	for(int k=h[i];k!=-1;k=edge[k].nex){
		int v=edge[k].to;
		if(!vis[v]){
			dfs(v);
		} 	
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fill(h,h+N,-1);
	fill(vis,vis+N,0);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Ad(x,y),Ad(y,x);
		//scanf("%d%d",&x[i],&y[i]);
	}
//	for(int i=1;i<=m;i++)
//		for(int j=1;j<=m;j++){
//			if(x[i]==x[j] && y[i]<y[j]){
//				int a;
//				a=y[j];
//				y[j]=y[i];
//				y[i]=a;
//			}
//		}
//	for(int i=1;i<=m;i++){
//		Ad(x[i],y[i]),Ad(y[i],x[i]);
//		printf("%d %d ",x[i],y[i]);
//	} 
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
		} 	
//	for(int j=1;j<=n;j++)	printf("%d ",a[j]);
	return 0;
}
