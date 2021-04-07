#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=5005;
const int maxm=5005;
struct node{
	int to;
	int next;
}e[maxm*2],E[maxm*2];
int k=0,kk=0;
int head[maxm*2],head2[maxm*2];
int r[maxm*2];
int bk[maxm*2],bk2[maxm*2];
bool vis[maxm];
void add(int u,int v){
	e[++k].next=head[u];
	e[k].to=v;
	head[u]=k;

}
void add2(int u,int v){
	E[++kk].next=head2[u];
	E[kk].to=v;
	head2[u]=kk;
}
void dfs2(int ,int );
int c[5005][10];
void dfs(int x,int step){
	if(step==n){
		for(int i=1;i<=step;i++){
			printf("%d ",r[i]);
			return ;
		}
	}
	for(int i=head[x];i;i=e[x].next){
//		if(bk[i]) break;
		int v=e[i].to;
		if(vis[v]) dfs(c[v][0],step);
		r[++step]=v;
		bk[i]=1;
		vis[v]=1;
		c[v][0]=i;
		cout<<v<<endl;
		dfs(v,step);
	//	vis[v]=0;
	//	bk[i]=0;
	}
}

void dfs2(int x,int step){
	if(step==n){
		for(int i=1;i<=step;i++){
			printf("%d ",r[i]);
			return ;
		}
	}
	for(int i=head2[x];i;i=E[x].next){
		if(bk2[i]) break;
		int v=E[i].to;
		if(!vis[v]) dfs(v,step);
		cout<<"2"<<" "<<v<<endl;
		r[++step]=v;
		bk2[i]=1;
		vis[v]=1;
		dfs2(v,step);
	//	vis[v]=0;
	//	bk[i]=0;
	}
}
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	r[1]=1;
	for(int i=head[3];i;i=e[i].next){
		cout<<e[i].to<<endl;
		}
	dfs(1,1);
	return 0;
}
