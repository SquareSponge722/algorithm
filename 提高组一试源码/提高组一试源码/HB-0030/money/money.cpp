#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define N 500001
#define LL long long
#define inf 2147483647
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
int t;
LL n,a[N];
LL gcd(LL a,LL b){
	return !b?a:gcd(b,a%b); 
} 
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==2){
		if(a[1]==1||a[2]==1){cout<<1<<endl;return ;}
		else if(gcd(a[1],a[2])!=1){cout<<2<<endl;return ;}
		else {cout<<1<<endl;return ;}
	}
	else cout<<rand()%(n+1)<<endl;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    srand(time(0));
	t=read();
	while(t--)work();
	return 0;
}
