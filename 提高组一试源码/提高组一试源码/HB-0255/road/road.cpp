#include<cstdio>
#include<cmath>
#include<stack>
#include<iostream>
using namespace std;
int read(){
	char ch=getchar();int x=0,y=1;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*y;
}
long long a[100005];
stack<long long > s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	long long ans=0,minn=10000005;
	for(int i=1;i<=n;i++)
		a[i]=read();
	s.push(0);
	for(int i=1;i<=n;i++){
		
		if(a[i]>s.top()){
			ans+=(a[i]-s.top());
			s.push(a[i]);
		}
		if(a[i]<s.top()){
			while(a[i]<s.top())s.pop();
			s.push(a[i]);
		}
			
	}
	cout<<ans;
	return 0;
}
