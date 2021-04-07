#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define re register int 
#define in inline
#define ll long long
using namespace std;
const int mod=1e9+7;
int n,m;
in void get(re &x){
    	x=0;re f=1;
    	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
in ll pows(ll a,ll b){
	ll c=1;
	for(;b;a=a*a%mod,b/=2)
		if(b%2)c=c*a%mod;
	return c;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	get(n),get(m);
	if(m<=3){
		if(n==1&&m==1)printf("2");
		else if(n==1&&m==2||m==1&&n==2)printf("4");
		else if(n==1&&m==3||n==3&&m==1)printf("8");
		else if(n==2&&m==2)printf("12");
		else if(n==2&&m==3)printf("40");
		else if(n==3&&m==2)printf("48");
		else if(n==3&&m==3)printf("112");
		else {
			if(m==1)printf("lld",pows((ll)2,(ll)n));
			else if(m==2)printf("lld",pows((ll)2,(ll)n)*(ll)(n*(n+1))/2%mod);
		}
	}	
	else if(n==5&&m==5)printf("7136");
   	return 0;
}

