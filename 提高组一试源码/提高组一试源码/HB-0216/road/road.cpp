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
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();		
	}
	x*=f;
	return x;
}
const int N=1e5+10;
int a[N];
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n=read();
	int cnt=0;
	for(register int i=1;i<=n;++i){
		a[i]=read();
		int delta=a[i]-a[i-1];
		if(delta>0)cnt+=delta;
	}
	printf("%d",cnt);
	return 0;
}
