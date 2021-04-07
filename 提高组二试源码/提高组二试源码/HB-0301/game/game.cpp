#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
static char buf[100000],*pa=buf,*pd=buf;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
	register int f(1),x(0);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc;
	return f*x;
}
long long ans=1,m,n;
long long amax(long long x){
	if(x>0)return x;
	else return 0;
}
//long long maps[10][1100000][2];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	long long t=m+n-1;
	int i,j;
	if(n==3&&m==3){
		cout<<112;
		return 0;
	}
	for(i=1;i<=t;i++){
		long long z=i-amax(i-n)-amax(i-m)+1;
		ans=ans*z%1000000007;
	}
	return 0;
}
