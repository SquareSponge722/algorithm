# include <cstdio>
# include <iostream>
# include <cstring>
# define N 250000
using namespace std;
long long  n,m,cnt;
const long long inf=1000000000000;
struct edge{
	long long  v,next;
}e[N]; long long  head[N];
long long  vis[N],ru[N],boo,val[N];
long long  x,fx,y,fy,sum,root,zhong;
long long  f[N][2];
void add(long long  u,long long  v){
	e[++cnt].v =v ;
	e[cnt].next =head[u];
	head[u]=cnt;
}
inline long long  read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	long long  res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-48;
	return res;
}
void dfs(long long  s,long long  fa){
	long long  to;
	f[s][1]=val[s];
	f[s][0]=0;
	for(long long  i=head[s];i;i=e[i].next ){
		to=e[i].v;
		if(to!=fa){
		dfs(to,s);
		if(s==x){
			if(fx==1){
				f[s][1]+=min(f[to][1],f[to][0]);
				f[s][0]=inf;
			}
			else{
				f[s][0]+=f[to][1];
				f[s][1]=inf;
			}
		}
		else if(s==y){
			if(fy==1){
				f[s][1]+=min(f[to][1],f[to][0]);
				f[s][0]=inf;
			}
			else{
				f[s][0]+=f[to][1];
				f[s][1]=inf;
			}
		}
		else{
		f[s][1]+=min(f[to][1],f[to][0]);
		f[s][0]+=f[to][1];
		}
		}
	}
}
int main (){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	long long  num; char c;
	cin>>c>>num;
	long long  u,v;
	for(long long  i=1;i<=n;++i){
		val[i]=read();
	}
	for(long long  i=1;i<n;++i){
		u=read(),v=read();
		add(u,v);
		add(v,u);
		ru[v]++;
		ru[u]++;
	}
	for(long long  i=1;i<n;++i){
		if(ru[i]==1){
			root=i;
			break;
		}
	}
	for(long long  mm=1;mm<=m;++mm){
		x=read(),fx=read(),y=read(),fy=read();
		dfs(root,0);
		if(min(f[root][0],f[root][1])==inf)	printf("-1\n");
		else printf("%lld\n",min(f[root][0],f[root][1]));
	}
	return 0;
}
