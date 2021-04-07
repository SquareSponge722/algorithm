#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define LL long long
#define inf 2147483647
#define N 1000001
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
struct node{int u,v,f;LL val;}p[N];
int n,m,w[N],g[N];
string type;
map<int,int>mp;
inline bool cmp(node x,node y){
	return x.val<y.val;
}
inline void solve(){
	LL ans=0;
	memset(g,-1,sizeof(g));
	for(int i=1;i<=n-1;i++)p[i].f=0;
	int a=read(),x=read(),b=read(),y=read();
	for(int i=1;i<=n-1;i++){
		if(p[i].u==a)g[a]=x;
		if(p[i].v==a)g[a]=x;
		if(p[i].u==b)g[b]=y;
		if(p[i].v==b)g[b]=y;
	}
	for(int i=1;i<=n;i++){
		int u=p[i].u,v=p[i].v;
		if(g[u]<1&&g[v]<1){
			if(g[u]==0&&g[v]==0){cout<<"-1"<<endl;return ;}
			else if(g[u]==0)g[v]=1,p[i].f=1;
			else if(g[v]==0)g[u]=1,p[i].f=1;
			else {
				if(w[u]<w[v])g[u]=1;
				else g[v]=1;
				p[i].f=1;
			}
		}
		if(g[u]==1||g[v]==1||p[i].f)p[i].f=1;
	}
	for(int i=1;i<=n;i++)
		if(g[i]==1)ans+=w[i];
	for(int i=1;i<=n;i++)
		if(!p[i].f){cout<<"-1"<<endl;return ;}
	cout<<ans<<endl;return ;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();cin>>type;
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n-1;i++)
		p[i].u=read(),p[i].v=read(),p[i].val=w[p[i].u]+w[p[i].v];
	sort(p+1,p+n-1+1,cmp);
	for(int i=1;i<=m;i++)solve();
	return 0;
}
