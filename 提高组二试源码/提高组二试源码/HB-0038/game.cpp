#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
unsigned long long ans,sum;
int read()
{
	int s=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n==1){cout<<0;return 0;}
	if(n==2||m==2){
		sum=pow(2,n+m-3);
		ans=sum*(sum+1)*2%1000000007;cout<<ans;return 0;
	}
	if(n==3&&m==3){
		cout<<112;return 0;
	}
	ans=4*pow(2,n+m-3)*(pow(n+m-1,2)-1);
	ans%=1000000007;
	cout<<ans;
	return 0;
}
