#include<iostream>
#include<cstdio>
#define N 110000
using namespace std; 
inline int read(){
	int sum=0,fu=1;char a=getchar();
	while(a>'9'||a<'0'){
		if(a=='-')fu=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum*fu;
}
long long ans;
int n,a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	a[i]=read();
	for(int i=n;i>=1;--i)
	a[i]-=a[i-1];
	for(int i=1;i<=n;++i){
		if(a[i]>0)ans+=a[i];
	}
	cout<<ans<<endl;
}
