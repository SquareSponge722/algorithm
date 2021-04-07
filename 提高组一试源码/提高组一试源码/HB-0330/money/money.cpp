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

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int a[101];
	int T(read());
	for(register int line=1;line<=T;line++){
		int n=(read());
		for(register int i=1;i<=n;i++)
			a[i]=read();
		if(n==1)	{cout<<n<<endl;continue;}
		sort(a+1,a+n+1);//ÉýÐòÅÅÁÐ 
		for(register int i=n;i>=2;i--){
			int mod(a[i]);
			for(register int j=i-1;j>=1;j--){
				mod%=a[j];
				if(mod==0){
					n--;
					break;
				}
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
