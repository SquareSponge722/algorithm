#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
static char buf[100000],*pa=buf,*pd=buf;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
	register int x(0),f(1);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc;
	return f*x;
}
const int N=51000;
struct edge{
	int to;
	int next;
	int w;
};
edge e[2*N];
int head[N],tot;
void add(int x,int y,int z){
	e[++tot].to=y;
	e[tot].next=head[x];
	e[tot].w=z;
	head[x]=tot;
}
int n,m,deep[N],t,total;
void dfs(int x,int fa){
	if(total<deep[x]){
		total=deep[x];
		t=x;
	}
	int i;
	for(i=head[x];i;i=e[i].next)
		if(e[i].to!=fa){
			deep[e[i].to]=deep[x]+e[i].w;
			dfs(e[i].to,x);
		}
}
void part1(){
	dfs(1,0);
	memset(deep,0,sizeof(deep));
	dfs(t,0);
	cout<<total;
}
int a[N],f[51000];
int dp(int x,int y,int z){
	if(y-x<z)return 0;
	if(z==1)return a[y]-a[x];
	int i,j,k;
	int ans=0;
	for(i=x+1;i<=y;i++)		
		for(k=1;k<z;k++)
			ans=max(ans,min(dp(x,i,k),dp(i,y,z-k)));
	return ans;
}
void part2(){
	int i;
	for(i=1;i<=n-1;i++)
		a[i+1]=a[i]+e[head[i]].w;
	cout<<dp(1,n,m);
}
int mem[2*N],cnt;
void part3(){
	int i;
	int ans=2147483647;
	for(i=head[1];i;i=e[i].next){
		mem[++cnt]=e[i].w;
	}
	sort(mem+1,mem+1+cnt,greater<int>());
	if(cnt/m>=2){
		for(i=1;i<=m;i++)
			mem[i]+=mem[2*m-i+1];
		for(i=1;i<=m;i++)
			ans=min(ans,mem[i]);
		cout<<ans;
		return;
	}
	else{
		for(i=2*m-cnt+1;i<=m;i++)
			mem[i]+=mem[2*m-i+1];
		for(i=1;i<=m;i++)
			ans=min(ans,mem[i]);
		cout<<ans;
		return;
	}
}
bool f1,f2;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	int i,x,y,z;
	f1=f2=1;
	for(i=1;i<=n-1;i++){
		x=read();y=read();z=read();
		if(y!=x+1)f1=0;
		if(x!=1)f2=0;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==1)part1();
	else if(f1)part2();
	else if(f2)part3();
	return 0;
}
