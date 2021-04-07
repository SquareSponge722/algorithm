#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100020;
int d[N],n,ans;
int tree[N<<2],lazy[N<<2],x,y;
bool flag=0,ok1,ok2;

void build(int l,int r,int rt){
	if(l==r){
		tree[rt]=d[l];
		return;	
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}

void pushdown(int l,int r,int rt){
	int mid=(l+r)>>1;
	tree[rt<<1]+=lazy[rt];
	tree[rt<<1|1]+=lazy[rt];
	lazy[rt<<1]+=lazy[rt];lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}

bool ok(int l,int r,int rt){
	if(l==r&&tree[rt]==0) return 0;
	if(tree[rt]!=0){
			if(!x&&!y) x=l,y=r;
			if(l<=(y+1)&&r>y) y=r;
			if(r>=(x-1)&&l<x) x=l;
		return 1;
	}
	int mid=(l+r)>>1;
	if(lazy[rt]&&l!=r) pushdown(l,r,rt);
	ok2=ok(mid+1,r,rt<<1|1);
	ok1=ok(l,mid,rt<<1);
	if(ok1||ok2) return 1;
	return 0;
}

void solve(int l,int r,int rt,int x,int y){
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		lazy[rt]-=1;
		tree[rt]-=1;
		return;
	}
	int mid=(l+r)>>1;
	if(lazy[rt]) pushdown(l,r,rt);
	solve(l,mid,rt<<1,x,y);
	solve(mid+1,r,rt<<1|1,x,y);
}

int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;++i){
		scanf("%d",d+i);
	}
	build(1,n,1);
	while(ok(1,n,1)){
		solve(1,n,1,x,y);
		ans++;
		x=0;y=0;flag=0;
	}
	printf("%d\n",ans);
	return 0;
}
