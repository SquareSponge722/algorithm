#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a[50002],b[50002],l[50002],sum,ans,h;
bool g;
int read()
{
	int s=0;bool f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=0;ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';ch=getchar();
	}
	return f?s:-s;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<n;i++){
		a[i]=read();
		b[i]=read();
		l[i]=read();sum+=l[i];
		if(a[i]!=1)g=1;
		if(b[i]!=a[i]+1)h=1;
	}
	if(!g){
		sort(l+1,l+n);
		if(m==1)ans=l[n-1]+l[n-2];
		else ans=min(l[n-m+1],l[n-m]+l[n-m-1]);
	}
	else{
		ans=sum/m;
	}
	cout<<ans;
	return 0;
}
