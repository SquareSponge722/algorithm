#include<bits/stdc++.h>
using namespace std;
int N,M,head[5010],cnt,ans[5010],NEXT,d,u,v;
bool b[5010],edge[5010][5010];
queue<int>q;
struct node{
	int next,to;
}a[10010];
void addnode(int x,int y){
	cnt++;
	a[cnt].to=y;
	a[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int x){
	//d++;
	for(int i=head[x];i!=-1;i=a[i].next){
		if(b[a[i].to]==0){
			b[a[i].to]=1;
			printf("%d ",a[i].to);
			dfs(a[i].to);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d",&u,&v);
		edge[u][v]=1;
		edge[v][u]=1;
	}
	for(int i=N;i>=1;i--)
		for(int j=N;j>=2;j--)
			if(edge[i][j])addnode(i,j);
	if(M==(N-1)){
		b[1]=1;
		printf("1 ");
		dfs(1);
	}
	else {
		q.push(1);
		b[1]=1;
		while(!q.empty()){
			u=q.front();
			printf("%d ",u);
			q.pop();
			for(int i=head[u];i!=-1;i=a[i].next){
				if (!b[a[i].to]){
					q.push(a[i].to);
					b[a[i].to]=1;
				}
			}
		}
	}
	return 0;
}
