#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 100007
using namespace std;
int e[maxn];

int n,m;
char type[2];
int main(){
freopen("defense.in","r",stdin);
freopen("defense.out","w",stdout);
scanf("%d%d%c",&n,&m,type);
if(type=="A2"){
    for(int i=1;i<=n;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	e[a]=b;
	}  
	for(int i=1;i<=m;i++){
	int a,x,b,y;
	scanf("%d%d%d%d",&a,&x,&b,&y);
	if(x==y){
	  printf("%d",-1);
	}
	else {
	int aa=a%2;
	int ans=0;
	if(x==0){
	for(int i=1;i<=n;i++){
	 if(i%2!=aa)ans+=e[i];
	}
	}
	if(y==0){
	for(int i=1;i<=n;i++){
	  if(i%2==aa)ans+=e[i];
	}
	}
	printf("%d",ans);
	}
}
}

return 0;
}
