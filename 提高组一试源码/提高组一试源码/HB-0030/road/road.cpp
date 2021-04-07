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
#define N 300001
#define LL long long
#define inf 2147483647
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
LL data[N],ans,n;
inline int findmin(){
	LL mini=0;data[mini]=inf;
	for(int i=1;i<=n;i++)
		if(data[mini]>data[i]&&data[i]!=0)mini=i;
	return mini;
}
inline bool check(){
	for(int i=1;i<=n;i++)
		if(data[i]!=0)return false;
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)data[i]=read();
	while(!check()){
		int pos=findmin(),l=pos,r=pos,g=data[pos];
		while(data[l-1]>0&&l-1>=1)l--;
		while(data[r+1]>0&&r+1<=n)r++;
		for(int i=l;i<=r;i++)data[i]-=g;
		ans+=g;
	}
	printf("%lld",ans);
	return 0;
}
