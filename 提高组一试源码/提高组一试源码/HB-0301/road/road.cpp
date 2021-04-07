#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
static char buf[100000],*pa=buf,*pd=buf;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
	register int x(0),f(1);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc;
	return f*x;
}
int n;
long long int a[101000],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
		a[i]=read();
	for(register int i=1;i<=n;i++)
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	cout<<ans;
	return 0;
}
