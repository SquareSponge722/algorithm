#include <bits/stdc++.h>
using namespace std;
const int N =5005;
int head[N],fun[N],n,m,x,y,en;

struct Edge{
	int to,next;
}edge[5005];
bool ok[5005];

void dfs(int x){
	cin>>x;
	ok[x]=1;
	int i,len={0};
	for(i=head[x];edge[i].to!=0;i=edge[i].next){
		len++;
		fun[len]=edge[i].to;
	}
	cout<<x<<endl;
	sort(fun+1,fun+len+1);
	for(int i=1;i<=len;i++){
		if(ok[fun[i]]==0) dfs(fun[i]);
		dfs(fun[i]);
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		edge[en].to=y;
		edge[en].next =head[x];
		head[x]=en;
		en++;
		edge[en].to=x;
		edge[en].next=head[y];
		head[y]=en;
	}
	dfs(1);
	return 0;
}
