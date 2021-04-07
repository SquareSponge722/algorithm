#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int x=(0),f=(1);char c=getchar(); 
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
	while(c>='0'&&c<='9')	{x=x*10+c-'0';	c=getchar();}
	return x*f;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	n=read(),m=read();
	int a[50000],b[50000],l[50000],temp=0;
	for(register int i=1;i<=n-1;i++)
		a[i]=read(),b[i]=read(),l[i]=read(),temp+=l[i];
	cout<<temp;
	return 0;
}
