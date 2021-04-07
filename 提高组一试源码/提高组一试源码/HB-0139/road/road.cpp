#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
int n;
int d[800000];
int stree[800000];
int smin[800000];
int smax[800000];
int lazy[800000];
int ans;
void build(int l,int r,int i);
void find(int L,int R,int i);
void update(int L,int R,int l,int r,int k,int i);
void pushdown(int l,int r,int i);
int l1,r1;
int changes;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int x=1;x<=n;x++){
		scanf("%d",&d[x]);
	}
	//printf("%d",d[3125]);
	//return 0;
	build(1,n,1);
	//printf("%d\n",smin[1]);
	while(smax[1]){
		find(1,n,1);
	}
	printf("%d",ans);
}
void build(int l,int r,int i){
	if(l==r){
		stree[i]=d[l];
		smax[i]=d[l];
		smin[i]=d[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	stree[i]=stree[i<<1]+stree[i<<1|1];
	smin[i]=min(smin[i<<1],smin[i<<1|1]);
	smax[i]=max(smax[i<<1],smax[i<<1|1]);
	return;
}
void find(int L,int R,int i){
	if(smin[i]){
		ans+=smin[i];
		update(1,n,L,R,(-smin[i]),1);
		return;
	}
	if(lazy[i]){
		pushdown(L,R,i);
	}
	if(!stree[i]){
		return;
	}
	int mid=(L+R)>>1;
	find(L,mid,i<<1);
	find(mid+1,R,i<<1|1);
	return;
}
void update(int L,int R,int l,int r,int k,int i){
	//printf("show:%d %d %d\n",L,R,i);
	if(l<=L&&r>=R){
		stree[i]+=k*(R-L+1);
		smin[i]+=k;
		smax[i]+=k;
		lazy[i]+=k;
		return;
	}
	if(lazy[i]){
		pushdown(L,R,i);
		
	}
	int mid=(L+R)>>1;
//	printf("xiangshi:%d %d %d %d\n",L,R,mid,i);
	if(mid>=l){
		update(L,mid,l,r,k,i<<1);
	}
	if(mid<r){
		update(mid+1,R,l,r,k,i<<1|1);
	}
	stree[i]=stree[i<<1]+stree[i<<1|1];
	smin[i]=min(smin[i<<1],smin[i<<1|1]);
	smax[i]=max(smax[i<<1],smax[i<<1|1]);
	return ;
}
void pushdown(int l,int r,int i){
	int mid=(l+r)>>1;
	stree[i<<1]+=lazy[i]*(mid-l+1);
	stree[i<<1|1]+=lazy[i]*(r-mid);
	smin[i<<1]+=lazy[i];
	smax[i<<1]+=lazy[i];
	smin[i<<1|1]+=lazy[i];
	smax[i<<1|1]+=lazy[i];
	lazy[i<<1]+=lazy[i];
	lazy[i<<1|1]+=lazy[i];
	lazy[i]=0;
	//printf("%d %d %d %d %d %d\n",l,r,i,stree[i],stree[i<<1],stree[i<<1|1]);
	return ;
}
