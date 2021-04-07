#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long n,m,tot,d[51000],nxt[102000],to[102000],v[102000],val[51000];
inline void ins(long long a,long long b,long long c){
	to[++tot]=b;
	nxt[tot]=d[a];
	d[a]=tot;
	v[tot]=c;
}
long long max_,id;
bool f[51000];
void dfs(long long x,long long fa,long long dist){
	if(dist>max_){
		max_=dist;
		id=x;
	}
	for(long long i=d[x];i;i=nxt[i]){
		long long u=to[i];
		if(u==fa)continue;
		dfs(u,x,dist+v[i]);
	}
}
bool g,h;
bool check(long long x){
	long long now=1,value=0,s=0;
	while(now<n){
		while(now<n&&value<=x){
			value+=val[now];
			now++;
		}
		if(now>=n&&value<x)return 1;
		s++;
		value=0;
	}
	return s<m;
}
struct node{
	long long v;
	node(long long aa){
		v=aa;
	}
	bool operator <(const node&other)const{
		return v>other.v;
	}
};
priority_queue<node>q;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long a,b,c;
	g=1;
	h=1;
	for(long long i=1;i<n;++i){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(b!=a+1)g=0;
		if(a!=1)h=0;
		ins(a,b,c);
		ins(b,a,c);
		val[i]=c;
	}
	if(m==1){
		max_=-1;
		dfs(1,0,0);
		max_=-1;
		dfs(id,0,0);
		printf("%lld\n",max_);
	}
	else{
		if(g){
			long long l=1,r=9999999999,ans=0;
			while(l<=r){
				long long mid=(l+r)>>1;
				if(check(mid)){
					r=mid-1;
				}
				else{
					l=mid+1;
					ans=mid;
				}
			}
			printf("%lld\n",ans);
		}
		else{
			if(h){
				for(long long i=1;i<n;++i)q.push(node(i));
				long long last=n-m-1;
				while(last){
					node a=q.top();
					q.pop();
					node b=q.top();
					q.pop();
					q.push(node(a.v+b.v));
				}
				node c=q.top();
				printf("%lld\n",c.v);
			}
		}
	}
	return 0;
}


