#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define LL long long
#define inf 2147483647
#define N 1000001
#define mod 1000000007
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
LL f[N],n,m;
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	f[1]=f[2]=1;
	for(int i=3;i<=9999990;i++)f[i]=(f[i-1]%mod+f[i-2]%mod)%mod;
	n=read(),m=read();
	cout<<f[n+m+1]<<endl;
	return 0;
}
