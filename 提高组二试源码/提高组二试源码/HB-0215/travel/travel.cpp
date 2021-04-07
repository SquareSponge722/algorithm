#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N=100005;
int n,m;
int flag[N],fa[N],cnt,head[N],nxt[N],to[N],a[N],b[N];
void qxx(int x,int y){
	cnt++;to[cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
}
void dfs(int x,int y){
	if(y==n){
		int judge=0;
		for(register int i=1;i<=n;i++){
			if(a[i]>b[i]){
				break;
			}
			if(a[i]<b[i]){
				judge=1;
				break;
			}
		}
		if(judge==1){
			for(register int i=1;i<=n;i++){
				b[i]=a[i];
			}
		}
		return;
	}
	else if(flag[x]==1){
		for(register int i=head[x];i;i=nxt[i]){
			int e=to[i];
			if(flag[e]==0){
				flag[e]=1;
				fa[e]=x;
				a[y+1]=e;
				dfs(e,y+1);
				fa[e]=0;
				flag[e]=0;
			}
		}
		if(fa[x]!=0){
			dfs(fa[x],y);
		}
	}
	else{
		flag[x]=1;
		for(register int i=head[x];i;i=nxt[i]){
			int e=to[i];
			if(flag[e]==0){
				flag[e]=1;
				fa[e]=x;
				a[y+1]=e;
				dfs(e,y+1);
				fa[e]=0;
				flag[e]=0;
			}
		}
		if(fa[x]!=0){
			dfs(fa[x],y);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++){
		b[i]=100005;
	}
	for(register int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		qxx(a,b);qxx(b,a);
	}
	a[1]=1;
	dfs(1,1);
	for(register int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
