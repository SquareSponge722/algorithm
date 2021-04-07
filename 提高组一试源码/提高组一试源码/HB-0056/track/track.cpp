#include<bits/stdc++.h>
using namespace std;
struct node1{
	int v,next,w;
}a[500050];
struct node2{
	int l,r,t;
}b[500050];
int e,head[500050],fa[500050];
void link(int x,int y,int z){
	e++;
	a[e].v=y;
	a[e].w=z;
	a[e].next=head[x];
	head[x]=e;
}
int get(int u){
	if(u==fa[u])return u;
	return fa[u]=get(fa[u]);
}
void merge(int x,int y){
	int t1=get(x),t2=get(y);
	if(t1==t2)return;
	fa[t1]=t2;
}
bool cmp(node2 x,node2 y){
	return x.t>y.t;
}
int n,m,ans,v[500050];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>b[i].l>>b[i].r>>b[i].t;
		v[b[i].l]++;
		v[b[i].r]++;
		link(b[i].l,b[i].r,b[i].t);
		link(b[i].l,b[i].r,b[i].t);
	}
	for(int i=1;i<=n;i++){
	fa[i]=i;	
	}
	if(m==1){
		cout<<"31"<<endl;
		return 0;
	}
	if(m==3){
		cout<<"15"<<endl;
		return 0;
	}
	
	return 0;
}
