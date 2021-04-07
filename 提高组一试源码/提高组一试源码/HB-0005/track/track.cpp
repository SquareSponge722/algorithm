#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=50005;
struct edge{
	int v,w,nt;
}e[N<<1];
int h[N],cnt=0;
inline void add(int u,int v,int w){
	e[++cnt].v=v;e[cnt].nt=h[u];e[cnt].w=w;h[u]=cnt;
	e[++cnt].v=u;e[cnt].nt=h[v];h[v]=cnt;e[cnt].w=w;
}
int n,m,x,y,z,op1=1,op2=1,sl=0,lmin=1<<30,lmax=0,la[N];  //op1:a=1  op2:a line
int d[N],maxd=-1,na=0;
void pre_dfs1(int u,int fa){
	if(d[u]>maxd){maxd=d[u];na=u;}
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;if(v==fa)continue;
		d[v]=d[u]+e[i].w;
		pre_dfs1(v,u);
	}
}
int ck1(int mid){
	int ct=0,np=0,ns=0;
	while(np<n){
		while(np<=n&&ns<mid){
			ns+=la[++np];
		}
		ct++;ns=0;
	}
	if(ct>m){return 1;}
	return 0;
}
int ck2(int mid){
	int ct=0,np=0,ns=0;
	while(np<n){
		while(np<=n&&ns<mid){
			ns+=la[++np];
		}
		ct++;
		if(np>=n&&ns<mid)return 0;
		ns=0;
		
	}
	if(ct>=m){return 1;}
	return 0;
}

int ck3(int mid){
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);lmin=min(lmin,z);lmax=max(lmax,z);
		add(x,y,z);if(op1&&x!=1)op1=0;la[i]=z;sl+=z;
		if(op2&&y!=x+1)op2=0;
	}
	if(m==n-1){
		printf("%d",lmin);return 0;
	}
	if(m==1){
		memset(d,-1,sizeof(d));
		d[1]=0;pre_dfs1(1,0);
		memset(d,-1,sizeof(d));
		d[na]=0;pre_dfs1(na,0);
		printf("%d",maxd);return 0;
	}
	if(op2){
		n--;
		int nl=lmin,nr=sl;
		while(nl<nr){
			int mid=nl+nr>>1;
			if(ck1(mid))nl=mid+1;
			else nr=mid;
		}
		if(!ck2(nl))nl--;
		printf("%d",nl);
		return 0;
	}
	if(op1){
		/*
		n--;
		sort(la+1,la+1+n);
		int nl=lmin,nr=sl;
		while(nl<nr){
			int mid=nl+nr>>1;
			if(ck3(mid))nl=mid+1;
			else nr=mid;
		}
		*/
		
		
	}
	return 0;
}

/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

*/

/*
6 2
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1

*/