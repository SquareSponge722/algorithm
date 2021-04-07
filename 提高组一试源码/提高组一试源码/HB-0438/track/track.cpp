#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define maxn 50000

struct Edge {
	int x,y,z;
	Edge() {}
	Edge(int xx,int yy,int zz) {
		x=xx,y=yy,z=zz;
	}
	bool operator < (const Edge& oth) const {
		return z>oth.z;
	}
};

int n,m;
int sum=0;

Edge e[maxn+5];

vector<Edge> tr[maxn+5];

int d[maxn+5];
void dfs1(int x,int fa) {
	for(int i=0; i<tr[x].size(); i++) {
		int y=tr[x][i].y,z=tr[x][i].z;
		if(y==fa) continue;
		d[y]=d[x]+z;
		dfs1(y,x);
	}
}

int Wab[maxn+5];

bool Judge(int mid) {
	int x=0,c=0;
	for(int i=1; i<n; i++) {
		if(Wab[i]+x>=mid) {
			c++;
			x=0;
		} else x+=Wab[i];
	}
	if(c>=m) return true;
	return false ;
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);

	read(n),read(m);

	bool isall1=true,isab=true;

	for(int i=1; i<n; i++) {
		read(e[i].x),read(e[i].y),read(e[i].z);
		if(e[i].x!=1) isall1=false;
		if(e[i].x+1!=e[i].y) isab=false;
		tr[e[i].x].push_back(e[i]);
		tr[e[i].y].push_back(Edge(e[i].y,e[i].x,e[i].z));
		sum+=e[i].z;
	}

	if(isab) {
		for(int i=1; i<n; i++) {
			Wab[e[i].x]=e[i].z;
		}

		int l=1,r=sum;
		while(l+1<r) {
			int mid=(l+r)/2;
			if(Judge(mid)) l=mid;
			else r=mid;
		}

		if(Judge(l+1)) l++;
		else if(!Judge(l)) l--;

		printf("%d",l);

		return 0;
	}

	if(m==1) {
		dfs1(1,0);
		int rt,ss=0;
		for(int i=1; i<=n; i++) if(d[i]>ss) ss=d[i],rt=i;
		memset(d,0,sizeof(d));
		dfs1(rt,0);
		ss=0;
		for(int i=1; i<=n; i++) if(d[i]>ss) ss=d[i];
		printf("%d",ss);
		return 0;
	}

	if(isall1) {
		sort(e+1,e+n);
		int ans;
		if(m<2*(n-1)){
			ans=1e9;
			for(int i=1;i<=m;i++) {
				ans=min(ans,e[i].z+e[2*m-i+1].z);
			}
		} else {
			ans=1e9;
			int s=(n-1)/2,t=m-s;
			for(int i=1;i<=t;i++) {
				ans=min(ans,e[i].z);
			}
			for(int i=t+1;i<=t+s;i++){
				ans=min(ans,e[i].z+e[2*s+2*t-1-i].z);
			}
		}
		printf("%d",ans);
		return 0;
	}

	if(m==n-1) {
		sort(e+1,e+n);
		printf("%d",e[n-1].z);
		return 0;
	}
	
	printf("%d",e[1].z);

	return 0;
}
