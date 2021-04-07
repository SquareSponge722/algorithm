#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s*w;
}
struct QWE {
	int t,w;
} p;
struct cmp {
	bool operator()(int x,int y) {
		return x<y;
	}
};
priority_queue<int,vector<int>,cmp>dl;
vector<QWE>v[50010];
int ans,anss,n,m,a,b,L,e[50010];
void dfs(int x,int f) {
	ans=max(ans,anss);
	for(int i=0; i<v[x].size(); i++) {
		if(v[x][i].t!=f) {
			anss+=v[x][i].w;
			dfs(v[x][i].t,x);
			anss-=v[x][i].w;
		}
	}
	return ;
}
bool ok;
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<n; i++) {
		a=read();
		b=read();
		L=read();
		p.t=b;
		p.w=L;
		if(a!=1)ok=1;
		e[i]=L;
		v[a].push_back(p);
		p.t=a;
		v[b].push_back(p);
	}
	if(ok==0) {
		sort(e+1,e+n);
		int anns=0x3f3f3f;
		if(m<=(n-1>>1))
			for(int i=1; i<=(n-1>>1); i++)anns=min(e[n-i]+e[n-2*m-1+i],anns);
		else 	if(m==n-1)anns=e[1];
		else {
			anns=0;
			for(int i=2; i/2+m<n; i+=2) {
				int aans=e[i+1];
				for(int j=1;j<=i/2;j++)
				aans=min(aans,e[j]+e[i-j+1]);
			anns=max(aans,anns);
			}
		}
		cout<<anns;
		return 0;
	}
	if(m==1) {
		for(int i=1; i<=n; i++) {
			anss=0;
			dfs(i,0);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
