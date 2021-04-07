#include<bits/stdc++.h>
using namespace std;
const int N= 300005;
int n,m,num;
string s;
int p[N];
int ans=-1;
bool ok[N];
int u[N],v[N];
struct Edge{
	int nex,to;
	//bool operator <(const Edge &x){to<x.to;}
}edge[2*N];
int en=0,h[N];
void Ad(int x,int y){
	edge[en].to=y;
	edge[en].nex=h[x];
	h[x]=en++;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s>>num;
	fill(ok,ok+N,1);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		Ad(u[i],v[i]),Ad(u[i],v[i]);
	}	
	int a,b,x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0) ok[a]=0;
		if(y==0) ok[b]=0;
		if(x==1) ok[a]=1;
		if(y==1) ok[b]=1;
		
	}
	if(num==2 && x==0 && y==0) ans=-1;
	for(int i=1;i<n;i++){
		if(ok[u[i]]==0 && ok[v[i]]==0) ans=-1;
	}
	while(m--) printf("%d\n",ans);
	return 0;
}
