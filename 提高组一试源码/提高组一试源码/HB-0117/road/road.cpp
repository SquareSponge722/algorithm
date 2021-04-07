#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define re register int
#define in inline
using namespace std;
int n,x,tmp,ans;
in void get(re &x){
	x=0;re f=1;
	register char c;
	while(!(c<='9'&&c>='0')){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	x*=f;	
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	get(n);
	for(re i=1;i<=n;i++){
		get(x);
		if(x>tmp)ans+=(x-tmp);
		tmp=x;
	}
	printf("%d",ans);
	return 0;
}
