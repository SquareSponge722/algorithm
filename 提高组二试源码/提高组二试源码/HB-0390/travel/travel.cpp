#include<bits/stdc++.h>
using namespace std;
int cnt,ans[5005],sum[5005],n,m,b[5005],end[5005],maxn,dui[10005],fa[5005];
struct yuansu {
	int x,y;
} bian[10005];
void dfs(int d) {
	ans[++cnt]=d;
	b[d]=1;
	int minn=5001;
	do{
		minn=5001;
		for(int i=sum[d-1]+1; i<=sum[d]; i++) {
			if(bian[i].y<minn&&!b[bian[i].y])minn=bian[i].y;
		}
		if(minn!=5001)
			dfs(minn);
	}while(minn!=5001);
	return;
}
int cmp(yuansu a,yuansu b) {
	return a.x<b.x;
}
void bfs() {
	int head=1,tail=2;
	dui[1]=1;
	b[1]=1;
	while(head!=tail) {
		for(int i=sum[dui[head]-1]+1; i<=sum[dui[head]]; i++) {
			if(!b[bian[i].y]) {
				b[bian[i].y]=1;
				fa[bian[i].y]=dui[head];
				dui[tail]=bian[i].y;
				tail++;
			}
		}
		head++;
	}
	return;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>bian[i].x>>bian[i].y;
		bian[i+m].x=bian[i].y;
		bian[i+m].y=bian[i].x;
	}
	sort(bian+1,bian+2*m+1,cmp);
	for(int i=1; i<=2*m; i++)
		if(bian[i].x!=bian[i+1].x)
			sum[bian[i].x]=i;
	bfs();
	for(int i=1; i<=n; i++) {
		maxn=0;
		for(int j=sum[i-1]+1; j<=sum[i]; j++) {
			if(bian[j].y!=fa[i])
				maxn=max(maxn,bian[i].y);
		}
		if(maxn==0)maxn=5001;
		end[i]=maxn;
	}
	cnt=0;
	memset(b,0,sizeof(b));
	dfs(1);
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";
	return 0;
}
