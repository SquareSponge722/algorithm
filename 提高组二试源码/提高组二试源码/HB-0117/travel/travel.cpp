#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define re register int 
#define in inline
using namespace std;
const int N=5001;
int n,m,x,y,vis[N],ans[N],cnt,t;
int e[N][5],num[N];
in void get(re &x){
    	x=0;re f=1;
    	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
in void dfs(re x){
	if(cnt==n)return;
	for(re i=1,k;i<=num[x];++i){
		k=e[x][i];
		if(vis[k])continue;
		vis[k]=1,ans[++cnt]=k;
		dfs(k);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	get(n),get(m);
	if(m==n-1){
		for(re i=1;i<=m;++i)
			get(x),get(y),e[x][++num[x]]=y,e[y][++num[y]]=x;
		for(re i=1;i<=n;++i)sort(e[i]+1,e[i]+1+num[i]);
		vis[1]=cnt=ans[1]=1,t=n;
		dfs(1);
		for(re i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
   	return 0;
}

