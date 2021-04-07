#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e6+10,inf=0x3f3f3f3f;
struct node {
	int l,r,del;
	node (int a,int b,int c) {
		l=a; r=b; del=c;
	}
};
inline int read() {
	int x=0,f=1; char ch;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,d[N],b[N];
ll ans;
queue<node>q;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) d[i]=read();
	q.push(node(1,n,0));
	while(!q.empty()) {
		node t=q.front(); q.pop();
		int min=inf; b[0]=0;
		for(int i=t.l;i<=t.r;i++) {
			if(d[i]-t.del<min) {
				min=d[i]-t.del; b[0]=0; b[++b[0]]=i;
			}
			else if(d[i]-t.del==min) b[++b[0]]=i;
		}
		ans+=min;
		int now=t.l;
		for(int i=1;i<=b[0];i++) {
			if(now<=b[i]-1) q.push(node(now,b[i]-1,t.del+min)),now=b[i]+1;
			else if(now==b[i]) now=b[i]+1;
		}
		if(now<=t.r) q.push(node(now,t.r,t.del+min)); 
	}
	printf("%lld",ans);
	return 0;
}

