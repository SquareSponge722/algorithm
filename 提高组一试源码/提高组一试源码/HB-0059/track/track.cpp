#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int i=head[x];i;i=h[i].next)
using namespace std;
struct edge{
	int next,to,w;
}h[100005];
struct bian{
	int from,w;
}b[50005];
int n,m,tot,kk,ans=0,head[50005];
bool vis[50005];
inline int read(){
	int k=1,x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if (ch=='-') k^=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return k?x:-x;
}
void add(int u,int v,int w){
	h[++tot].to=v;
	h[tot].w=w;
	h[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u,int total){
	ans=max(ans,total);
	TU(u){
		int v=h[i].to,w=h[i].w;
		if (!vis[v]){
			vis[v]=1;
			dfs(v,total+w);
			vis[v]=0;
		}
	}
}
bool check(int x){
	int cnt=0,k=0;
	FOR(i,1,kk){
//		cout<<i<<" "<<h[i].to<<" "<<h[i].w<<"\n";
		if(cnt<x) cnt+=b[i].w;
		if (cnt>=x) {
			cnt=0;
			k++;
		}
	}
//	cout<<k<<"\n";
	if (k>=m) return true;
	return false;
}
bool comp(bian x,bian y){
	return x.from<y.from;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool f=1;
	n=read(),m=read();
	int u,v,w,minw=0x7fffffff,sum=0;
	FOR(i,1,n-1){
		u=read(),v=read(),w=read();
		if (v!=u+1) f=0;
		else b[++kk].from=u,b[kk].w=w;
		add(u,v,w),add(v,u,w);
		minw=min(minw,w);
		sum+=w;
	}
	if (f){
		sort(b,b+kk+1,comp);
		int l=minw,r=sum,ans;
//		cout<<tot<<"\n";
		while(l<=r){
			int mid=(l+r)>>1;
//			cout<<mid<<"\n";
			if (check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans;
		return 0;
	}
	if (m==1){
		ans=0;
		FOR(i,1,n) {
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i,0);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
