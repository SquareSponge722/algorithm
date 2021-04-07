#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
const int N=100005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
	return s;
}
int n;
int d[N],f[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) d[i]=read();
	f[1]=d[1];
	for(int i=2;i<=n;i++) {
		f[i]=f[i-1];
		if(d[i]>d[i-1]) f[i]+=d[i]-d[i-1];
	}
	printf("%d",f[n]);
	return 0;
}
