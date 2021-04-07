#include<bits/stdc++.h>
using namespace std;
int n,m,en,far,dee,add1,add2,mi(0x7fffffff),ans;
int head[50005];

struct Edge{
	int f,t,n,v;
	bool ok;
	bool operator < (Edge x)const{
		return x.v<v;
	}
}A[50005];

void dfs(int x,int y,int deep){
	if (A[y].ok==1) return;
	if (deep>dee) {
		dee=deep;
		far=x;
	}
	A[y].ok=1;
	for (int i=head[x];;){
		dfs(A[i].t,head[A[i].t],deep+A[i].v);
		if (A[i].n==0) break;
		else i=A[i].n;
	}
	A[y].ok=0;
	return;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int x,y,v,i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&v);
		ans+=v;
		if (x==1) add1++;
		if (y==x+1) add2++;
		en++;
		A[en].f=x;
		A[en].t=y;
		A[en].v=v;
		A[en].n=head[x];
		head[x]=en;
		en++;
		A[en].f=y;
		A[en].t=x;
		A[en].v=v;
		A[en].n=head[y];
		head[y]=en;
	}
	if (m==1){
		dfs(1,head[1],0);
		dfs(far,head[far],0);
		printf("%d\n",dee);
		return 0;
	}
	if (add1==n-1){
		sort(A+1,A+en+1);
		for (int i=1;i<=en;i+=2){
			if (mi>A[i].v+A[en-i].v) mi=A[i].v+A[en-i].v;
		}
		printf("%d\n",mi);
	}
	if (add2==n-1){
		int minw,minz(0x7fffffff);
		int C[50005];
		for (int x=1,i=1;i<n;i++){
			C[i]=A[x].v;
			x=A[head[x]].t;
		}
		bool B[50005];
		for (int i=1;i<n-m;i++){
			minz=0x7fffffff;
			for (int j=1;j<n;j++){
				if (B[i]) continue;
				if (minz>C[i]) {
					minz=C[i];
					minw=i;
				}
			}
			B[minw]=1;
			
		}
		
		printf("%d\n",ans/(n-m));
	}
	return 0;
}
