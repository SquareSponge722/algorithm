#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 110
int a[N];
int T,n;
int Gcd(int a,int b){
	return (b==0) ? a : a%b;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		int prime1=0,prime2=0,minget=0;
		bool flag=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)
				if(Gcd(i,j)==1){
					prime1=i,prime2=j;
					flag=1;break;
				} 
			if(flag) break;
		}
		if(prime1==0 && prime2==0){
			cout<<n<<endl;
		}
		else {
			minget=prime1*prime2-prime1-prime2;
			for(int i=1;i<=n;i++){
				//if(a[i]<minget && a[i]!=prime1 && a[i]!=prime2 && a[i]%prime1!=0 && a[i]%prime2!=0) ans++;
				if(a[i]==prime1 || a[i]==prime2) continue;
				else if(a[i]<minget && a[i]%prime1!=0 && a[i]%prime2!=0) ans++;
			}
			cout<<ans+2<<endl;			
		}
	}
	return 0;
}
