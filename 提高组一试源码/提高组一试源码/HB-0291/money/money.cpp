#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(k,i,j) for(int k = i;k <= j; ++k)
#define FOR(k,i,j) for(int k = i;k >= j; --k)
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int maxn = 2e2;
const int maxv = 5e4;
int a[maxn];
bool v[maxv];
int T,n,ans;
void init(){
	n = read();
	rep(i,1,n) a[i] = read();
}
//一个数被抛弃当且仅当：
//1。 倍数
//2。 另两个数可以组成这个数 
void work(){
	memset(v,0,sizeof(v));
	ans = n;
	sort(a+1,a+n+1);
	int minx = a[1],maxx = a[n];
	rep(i,1,n){
		int x = a[i];
		if(x > maxx/2) break;
		rep(j,2,maxx/x){
			v[x*j] = 1;
		}
	}
	for(int i = 2;i <= n; ++i){
		int K = 0;
		for(int j = a[i]; j>= 0; j-=a[K]){
			++K;
			for(int k = 1;k <= i; ++k){
				v[a[i]-a[k]] = 1;
			}
		}
	}
	rep(i,1,n) if(v[a[i]]) ans--;
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T = read();
	while(T--){
		init();
		work();	
	}
	return 0;
} 
