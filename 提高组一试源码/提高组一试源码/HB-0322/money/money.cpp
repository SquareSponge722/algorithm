#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
const int N=105;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
	return s;
}
int a[N];
int f[25005];
int dfs(int i,int la,int k){
	if(i<0) return 0;
	if(f[i]==1) return f[i];
	for(int j=la;j<=k;j++) {
		if(i%a[j]==0) return (f[i]=1);
		if(dfs(i-a[j],j,k)) return (f[i]=1);
	}
	return 0;
}
inline int check(int i){
	for(int j=1;j<i;j++) if(a[i]%a[j]==0) return 1;
	return 0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,m;
	T=read();
	while(T--){
		memset(f,0,sizeof(f));
		n=read();m=0;
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		if(a[1]==1||n==1) {puts("1");continue;}
		f[a[1]]=1;m=1;
		for(int i=2;i<=n;i++){
			if(check(i)) continue;
			if(!dfs(a[i],1,i-1))
				m++,f[a[i]]=1;
		}
		printf("%d\n",m);
	}
	return 0;
}
