#include<bits/stdc++.h>
using namespace std;
int n,t,T,a[1000],sum;
int gcd(int a,int b){
      if(b==0)return a;
      return gcd(b,a%b);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		sum=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(gcd(a[i],a[j])!=1){
			sum--;	
			}
		}
		if(sum<=0)sum=1;
		cout<<sum<<endl;
	}
	return 0;
}
