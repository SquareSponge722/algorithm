#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<bitset>
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
int b[100005];
bitset<100005> bb;
int a[1005],n,T;
ll ans;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    T=read();
    //double st=clock();
    if(n<=25)
    {
    while(T--)
    {
    	n=read();int maxx=0;
    	for(int i=1;i<=n;i++) a[i]=read(),maxx=max(maxx,a[i]);
    	sort(a+1,a+1+n);
    	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
    	ans=0;
    	for(int i=1;i<=25000;i++) b[i]=0;
    	b[0]=1;
    	for(int i=1;i<=n;i++)
    	{
    		if(b[a[i]]) continue;
    		ans++;
    		for(int j=a[i];j<=maxx;j++) 
			if(b[j-a[i]]) b[j]=1;
			//for(int j=1;a[i]*j<=maxx;j++) b|=(b<<a[i]);
		}
		cout<<ans<<endl;
	}
    }
	else{
		while(T--)
		{
		n=read();int maxx=0;
    	for(int i=1;i<=n;i++) a[i]=read(),maxx=max(maxx,a[i]);
    	sort(a+1,a+1+n);
    	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
    	ans=0;
		for(int i=1;i<=25000;i++) bb[i]=0;
    	bb[0]=1;
    	for(int i=1;i<=n;i++)
    	{
    		if(bb[a[i]]) continue;
    		ans++;
    		/*for(int j=a[i];j<=maxx;j++) 
			if(b[j-a[i]]) b[j]=1;*/
			for(int j=1;a[i]*j<=maxx;j++) bb|=(bb<<a[i]);
		}
		cout<<ans<<endl;
	}
    }
	//double en=clock();
	//cout<<en-st<<endl;
	return 0;
}
