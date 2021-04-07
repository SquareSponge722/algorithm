#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ymd(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
typedef long long ll;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxm=100005,maxn=100005;
const ll inf=0x7fffffffffffffff;
ll minn=inf;
struct edge {
	int u,v,next;
} e[maxm<<1];
int cnt=0,n,m,head[maxn],p[maxn];
char must[maxn];
void add(int u,int v) {
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
ll paint(int l,int r) {
	ll f[r-l+5][2];
	f[0][0]=f[0][1]=0;
	FOR(i,l,r) {
		f[i-l+1][0]=f[i-l][1];
		f[i-l+1][1]=f[i-1][0]+p[i];
	}
	return min(f[r-l+1][1],f[r-l+1][0]);
}
void solve1() { //i i+1
	FOR(i,1,m) {
		int a=read(),x=read(),b=read(),y=read();
		if(x==0&&y==0) {
			printf("-1\n");
			continue;
		}
		ll sum=0;
		if(a>b) {
			swap(a,b);
			swap(x,y);
		}
		if(x==1) {
			sum+=p[a];
			sum+=paint(1,a-1);
		} else sum+=paint(1,b-1);
		if(y==1) {
			sum+=p[b];
			sum+=paint(b+1,n);
		} else sum+=paint(a+1,n);
		printf("%ld\n",sum);
	}
	return ;
}
bool vis[maxn];
int num;
void dfs(int x,int bj,ll sum,int step) {
//	printf("%d %d %ld %d\n",x,bj,sum,num);
	if(num>minn)return ;
	if(step>n) {
		minn=min(minn,sum);
	}
	if(bj==1) {
		for(int i=head[x]; i; i=e[i].next) {
			int v=e[i].v;
			if(vis[v])continue;
			vis[v]=1;
			num++;
			if(must[v]==1)//jian
				dfs(v,1,sum+p[v],step+1);

			else if(must[v]==2)//bujian
				dfs(v,0,sum,step+1);

			else {
				dfs(v,1,sum+p[v],step+1);
				dfs(v,0,sum,step+1);

			}
		}
	} else if(bj==0) {
		for(int i=head[x]; i; i=e[i].next) {
			int v=e[i].v;
			if(must[v]==2)return ;
			dfs(v,1,sum+p[v],step+1);
		}
	}
}
void solve2() {
	FOR(i,1,m) {
		minn=inf;
		num=0;
		int a=read(),x=read(),b=read(),y=read();
		must[a]=2-x;
		must[b]=2-y;
//		printf("%d %d\n",must[a],must[b]);
		dfs(a,x,0,1);
		if(minn!=inf)
		printf("%ld\n",minn);
		else printf("-1\n");
	}
}
void Zack() {
	string str;
	n=read(),m=read();
	cin>>str;
	FOR(i,1,n)p[i]=read();
	FOR(i,2,n) {
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	if(str=="A3")solve1();
//	else if(str=="")
	else solve2();
	return ;
}
int main() {
	ymd("defense");
	Zack();
//	cout<<minn<<endl;
	return 0;
}
