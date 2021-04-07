#include<bits/stdc++.h>
#define add(x,y) edge[++cnt]=node(y,head[x]),head[x]=cnt
struct node {
	int ver,to;
	node(int ver=0,int to=0):ver(ver),to(to) {}
};
using namespace std;
const int MAXN=100010;
void dp(int u,int fa);
void DPZ(int u);
int ZX,L,R;
long long f[MAXN][2],ff[MAXN][2];
int faa[MAXN];
inline char nc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int read() {
	int x=0;
	char c=nc();
	while(!isdigit(c))c=nc();
	while(isdigit(c))x=x*10+c-48,c=nc();
	return x;
}
char read1() {
	char c=nc();
	while(!isalpha(c))c=nc();
	return c;
}
void read2() {
	char c=nc();
	while(!isdigit(c))c=nc();
}
int n,m,T,cnt=-1;
int a[MAXN],head[MAXN];
node edge[MAXN<<1];
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,-1,sizeof(head));
	n=read(),m=read();
	char C=read1();
	read2();
	for(int i=1; i<=n; i++)a[i]=read();
	int u,ver;
	for(int i=1; i<n; i++) {
		u=read();
		ver=read();
		add(u,ver);
		add(ver,u);
	}
	srand(19260817);
	int S=1;
	if(C=='A')S=n+1>>1;
	else if(n>=100000&&C!='B')S=rand()%n+1;
	add(S,0);
	add(0,S);
	int or1,or2;
	dp(S,0);
	f[0][0]=f[0][1]=min(f[S][0],f[S][1]);
	faa[0]=-1;
	while(m--) {
		u=read();
		or1=read();
		ver=read();
		or2=read();
		if((faa[u]==ver||faa[ver]==u)&&!(or1|or2)) {
			puts("-1");
			continue;
		}
		ff[u][or1]=f[u][or1];
		ff[u][or1^1]=0x3f3f3f3f;
		ff[ver][or2]=f[ver][or2];
		ff[ver][or2^1]=0x3f3f3f3f;
		DPZ(u);
		DPZ(ver);
		printf("%lld\n",min(ff[0][0],ff[0][1]));
		memset(ff,0,sizeof(ff));
	}
}
void dp(int u,int fa) {
	faa[u]=fa;
	f[u][1]=a[u];
	for(int i=head[u]; i!=-1; i=edge[i].to) {
		if(edge[i].ver==fa)continue;
		dp(edge[i].ver,u);
		f[u][0]+=f[edge[i].ver][1];
		f[u][1]+=min(f[edge[i].ver][0],f[edge[i].ver][1]);
	}
}
void DPZ(int u) {
	bool ok=false;
	for(int i=faa[u]; i!=-1; i=faa[i]) {
		if(ff[i][1]&&ok==false) {
			ok=true;
			if(ff[i][1]<0x3f3f3f3f)ff[i][1]=a[i];
			if(ff[i][0]<0x3f3f3f3f)ff[i][0]=0;
			for(int j=head[i]; j!=-1; j=edge[j].to) {
				if(edge[j].ver==faa[i])continue;
				if(!ff[edge[j].ver][0]) {
					ff[i][0]+=f[edge[j].ver][1];
					ff[i][1]+=min(f[edge[j].ver][0],f[edge[j].ver][1]);
				} else {
					ff[i][0]+=ff[edge[j].ver][1];
					ff[i][1]+=min(ff[edge[j].ver][0],ff[edge[j].ver][1]);
				}
			}
		} else {
			ff[i][1]=a[i];
			ff[i][0]=0;
			for(int j=head[i]; j!=-1; j=edge[j].to) {
				if(edge[j].ver==faa[i])continue;
				if(!ff[edge[j].ver][0]) {
					ff[i][0]+=f[edge[j].ver][1];
					ff[i][1]+=min(f[edge[j].ver][0],f[edge[j].ver][1]);
				} else {
					ff[i][0]+=ff[edge[j].ver][1];
					ff[i][1]+=min(ff[edge[j].ver][0],ff[edge[j].ver][1]);
				}
			}
		}
	}
}
