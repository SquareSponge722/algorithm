#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read()
{
	char ch=getchar(),last=' ';ll ans=0;
	while(ch<'0'||ch>'9'){
		last=ch;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';ch=getchar();
	}
	if(last=='-') ans=-ans;
	return ans;
}
ll a[1000005],n;
ll ans,last;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	last=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>last) ans+=a[i]-last;
		last=a[i];
	}
	cout<<ans;
	return 0;
}
