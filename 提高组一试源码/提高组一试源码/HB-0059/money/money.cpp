#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
int n,a[105],maxx,ans;
inline int read(){
	int k=1,x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if (ch=='-') k^=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return k?x:-x;
}
bool f=0;
void dfs(int x,int sum,int tot){
	if (tot==sum){
		f=1;
		return;
	}
	if (x>maxx) return;
	if (f) return;
	if (tot>sum) return;
	FOR(i,0,(sum-tot)/a[x]){
		dfs(x+1,sum,tot+a[x]*i);
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--){
		memset(a,0,sizeof(a));
		n=read();
		FOR(i,1,n) a[i]=read();
		sort(a+1,a+n+1);ans=n;
//		FOR(i,1,n)cout<<a[i]<<" ";cout<<'\n';
		ROF(i,n,1){
			f=0,maxx=i-1;
			dfs(1,a[i],0);
			if (f) ans--;
		}
//		FOR(i,1,n) if (!used[i]) cout<<a[i]<<" ";cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}/*
1
54
74 36 49 81 57 76 93 50 45 69 75 83 59 98 70 80 54 37 92 84 91 58 11 
16 96 94 38 55 97 73 46 72 47 51 44 89 90 31 100 99 39 82 65 87 41 79 
86 34 95 63 52 12 88 53
*/
