#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d[100002],g,i;
long long ans=0;
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++){
		d[i]=read();
		if(d[i]>d[i-1]){
			ans+=d[i]-g;
			g=d[i];
		}
		else g=d[i];
	}
	cout<<ans;
	return 0;
}
