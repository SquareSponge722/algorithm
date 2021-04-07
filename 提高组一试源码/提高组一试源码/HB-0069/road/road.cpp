#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;

inline long long read(){
	
	long long x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
	
}

const int N=100005;
long long ans,n,d[N];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		d[i]=read();
		if(d[i]<d[i-1]){
			ans+=d[i-1]-d[i];
		}
	}
	ans+=d[n];
	cout<<ans<<endl;
	return 0;
	
}
