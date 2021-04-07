#include<iostream>
#include<cstdio>
#include<algorithm>
#define fr(i,n) for(int i=1;i<=n;++i)
#define fro(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=5050;
int n,m,step,final_ans[maxn],ans[maxn],d[maxn],sum[maxn],que[maxn<<2];
bool nan[maxn][maxn],col[maxn],lin[maxn],cir[maxn];
struct edge {
	int x,y,num;
}ed[maxn];
namespace part1 {
	void dfs(int a) {
		ans[step]=a;
		step++;
		lin[a]=1;
		fr(i,n) if(lin[i]==0&&nan[i][a]==1) dfs(i);
		return;
	}
	void work() {
		int a,b;
		while(m--) {
			scanf("%d%d",&a,&b);
			nan[a][b]=nan[b][a]=1;
		}
		step=1;
		dfs(1);
		fr(i,n) cout<<ans[i]<<" ";
		return;
	}
}
namespace part2 {
	bool cmp(edge a,edge b) {
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
	void dfs(int a,int b) {
		if(step==n-1) {
			bool f=0;
			ans[n]=a;
			fr(i,n) {
				if(ans[i]<final_ans[i]) f=1;
				if(ans[i]>final_ans[i]&&!f) return;
				final_ans[i]=ans[i];
			}
		}
		step++;
		ans[step]=a;
		lin[a]=1;
		fro(i,d[a-1]+1,d[a]) if(lin[ed[i].y]==0&&ed[i].num!=b) dfs(ed[i].y,b);
		return;
	}
	void work() {
		int a,b;
		fr(i,m)  {
			scanf("%d%d",&a,&b);
			d[a]++;d[b]++;
			ed[i]=(edge){ a,b,i };
			ed[i+m]=(edge){ b,a,i };
		}
		fr(i,n) d[i]+=d[i-1];
		sort(ed+1,ed+2*m+1,cmp);
		fr(i,n) final_ans[i]=2147483647;
		fr(i,m) {
			step=0;
			fr(j,n) lin[j]=0,ans[j]=0;
			dfs(1,i);
//fr(i,n) cout<<ans[i]<<" ";cout<<endl;
		}
		fr(i,n) cout<<final_ans[i]<<" ";
		return;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	if(m==n-1) part1::work();
	else part2::work();
	return 0;
}
