#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define re register int 
#define in inline
using namespace std;
const int N=100050;
int n,m,x,y,hd[N],esz,a[N],k1,k2,k3,k4;
int e[N][5],num[N];
char cc[10];
in void get(re &x){
    	x=0;re f=1;
    	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
in bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	freopen("defense,in","r",stdin);
	freopen("defense.out","w",stdout);
	get(n),get(m);
	scanf("%s",cc);
	for(re i=1;i<=n;++i)get(a[i]);
	for(re i=1;i<n;++i)get(x),get(y),e[x][++num[x]]=y,e[y][++num[y]]=x;
	for(re i=1;i<=n;++i)sort(e[i]+1,e[i]+1+num[i],cmp);
	for(re i=1;i<=m;++i){
		get(k1),get(k2),get(k3),get(k4);
	}
   	return 0;
}

