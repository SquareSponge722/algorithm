#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();		
	}
	x*=f;
	return x;
}
const int N=110;
int a[N];
int T,n;
int f,cnt;
void dfs(int x,long long ct)
{
	if(f)return;
	if(ct>a[x])return;
	if(ct==a[x]){
		f=1;
		return;
	}
	for(register int i=1;i<=n;++i){
		if(i!=x)
			dfs(x,ct+a[i]);
	}
}
int main() 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		memset(a,0,sizeof(a));
		f=0;cnt=0;
		n=read();
		for(register int i=1;i<=n;++i)a[i]=read();
		for(register int i=1;i<=n;++i){
			f=0;
			dfs(i,0);
			if(!f)cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
