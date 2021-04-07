#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define rg register

using namespace std;

const int N=5000+10;
const int inf=0x3f3f3f;
int n,m;
bool pic[N][N];
bool flag[N];
int f[N],c[N],a[N];
int tot,coc;
void picture(int x,int y){pic[x][y]=true;pic[y][x]=true;}
void dfs(int x){
	if(coc==n)return;
	flag[x]=true;
	f[++coc]=x;
	for(int i=1;i<=n;i++)
		if(!flag[i]&&pic[x][i])dfs(i);
}
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,inf,sizeof(f));
	memset(c,inf,sizeof(c));
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		picture(u,v);
	}
	for(int i=1;i<=n;i++){
		bool check=true;
		memset(f,inf,sizeof(f));
		coc=0;
		dfs(i);
		for(int i=1;i<=coc;i++)
			if(f[i]>c[i]){check=false;break;}
		if(check){
			memset(c,inf,sizeof(c));
			for(rg int i=1;i<=coc;i++)c[i]=f[i];
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",c[i]);
	return 0;
	
}
