#include<bits/stdc++.h>
using namespace std;
int n,m,a1,b1,st,en;
bool x,y;
int e=1,m1;
char ch;
struct node {
	int u,v;
} a[200001];
int head[200001];
int cost[100001];
bool ok;
int sum;
void addnode(int u,int v) {
	a[e].u=u;
	a[e].v=v;
	head[u]=e;
	e++;
}
bool defense(int city1,bool cho1,int city2,bool cho2) {
	sum=0;
	bool used[20001]={0};
	if(cho1==0&&cho2==0) {
		if(city1==a[head[city2]].v||city2==a[head[city1]].v){
			return false;
		}
	}
	sum+=cost[city1]*cho1+cost[city2]*cho2;
	used[city1]=1;
	used[city2]=1;
	int incho1=!cho1;
	int incho2=!cho2;
	for(int i=1;i<=2*n-2;i++){
		if(a[i].u==city1&&!used[a[i].v]){
			sum+=cost[a[i].v]*incho1; used[a[i].v]=1;
		} 
		else if(a[i].v==city1&&!used[a[i].u]){
			sum+=cost[a[i].u]*incho1;used[a[i].u]=1;
		} 
		else if(a[i].v==city2&&!used[a[i].u]){
			sum+=cost[a[i].u]*incho2;used[a[i].u]=1;
		}
		else if(a[i].u==city2&&!used[a[i].v]){
			sum+=cost[a[i].v]*incho2;used[a[i].v]=1;
		}	
	}
	for(int i=1;i<=2*n-2;i++){
		if(a[i].u==a[head[city1]].v&&!used[a[i].v]){
			sum+=cost[a[i].v]*cho1; used[a[i].v]=1;
		} 
		else if(a[i].v==a[head[city1]].v&&!used[a[i].u]){
			sum+=cost[a[i].u]*cho1;used[a[i].u]=1;
		} 
		else if(a[i].v==a[head[city2]].v&&!used[a[i].u]){
			sum+=cost[a[i].u]*cho2;used[a[i].u]=1;
		}
		else if(a[i].u==a[head[city2]].v&&!used[a[i].v]){
			sum+=cost[a[i].v]*cho2;used[a[i].v]=1;
		}	
	}
	return true;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>ch>>m1;
	for(int i=1; i<=n; i++) {
		scanf("%d",&cost[i]);
	}
	for(int i=1; i<=n-1; i++) {
		scanf("%d%d",&st,&en);
		addnode(st,en);
		addnode(en,st);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d%d",&a1,&x,&b1,&y);
		if(defense(a1,x,b1,y)) {
			printf("%d\n",sum);
			continue;
		}else cout<<"-1"<<endl;
	}
}
