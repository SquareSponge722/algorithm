#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int N=100005,inf=1e8;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
	return s;
}
int n,m;string Ttype;
int p[N];
vector<int> G[N];
set<int> s[N];
ll f[2005][2];
ll F[2005][2][2];
void dfs(int u,int fa,int y,int b){
	f[u][1]=p[u];
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v!=fa){
			dfs(v,u,y,b);
			if(y==v){
				if(b==1) {
					f[u][0]+=f[v][1];
					f[u][1]+=f[v][1];
				}else{
					f[u][0]=inf;
					f[u][1]+=f[v][0];
				}
			}
			else{
			f[u][0]+=f[v][1];
			f[u][1]+=min(f[v][0],f[v][1]);
		}
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>Ttype;
	for(int i=1;i<=n;i++) p[i]=read();
	int u,v;
	for(int i=1;i<n;i++){
		u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		s[u].insert(v);s[v].insert(u);
	}
	if(n<=2000){
		int a,b;
		while(m--){
			memset(f,0,sizeof(f));
			u=read(),a=read(),v=read(),b=read();
			if(a==0&&b==0) if(s[u].find(v)!=s[u].end()){
				puts("-1");continue;
			}
			dfs(u,0,v,b);
			printf("%lld\n",f[u][a]);
		}
		//dfs(1,0);
		//cout<<f[1][0]<<' '<<f[1][1];
		return 0;
	}
	if(Ttype[0]=='A'){
		if(Ttype[0]=='1'){
			int a,b;
			while(m--) {
				u=read(),a=read(),v=read(),b=read();
				
			}
		}else{
			for(int i=1;i<=n;i++) {
				F[i][0][1]=min(F[i-1][0][0],F[i-1][0][1])+p[i];
				F[i][0][0]=F[i-1][0][1];
			}
			for(int i=n;i>=1;i--){
				F[i][1][1]=min(F[i+1][1][0],F[i+1][1][1])+p[i];
				F[i][1][0]=F[i+1][1][1];
			}
			int a,b;
			while(m--) {
				u=read(),a=read(),v=read(),b=read();
				if(a==0&&b==0){puts("-1");continue;}
				if(u>v) swap(u,v),swap(a,b);
				printf("%lld\n",F[u][0][a]+F[v][1][b]);
			}
		}
	}
	return 0;
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
