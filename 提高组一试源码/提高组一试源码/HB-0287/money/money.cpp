#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],pd[100001],ans,ok,okk;
int gcd(int a,int b){
	if(b==0) return a;
	else gcd(b,a%b);
}
int zs(int x){
	if(x==0||x==1) return 0;
	if(x==2) return 1;
	for(int i=2;i<=sqrt(x+1);i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		okk=1,ok=0;
		cin>>n;
		memset(pd,0,sizeof(pd));
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1) cout<<1<<endl,n=1;
		}
		if(n>5){
			for(int i=1;i<=n;i++)
			if(!zs(a[i])) okk=0;
			if(okk) cout<<n<<endl;
			continue;
		} 
		if(n==2){
			if(a[1]%a[2]==0||a[2]%a[1]==0) cout<<1<<endl;
			else cout<<2<<endl;
		}
		else if(n==3){
			ans=n;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(i!=j&&i!=k&&j!=k){
					if(a[i]+a[j]==a[k]&&!pd[i+j]){
						ans--;pd[i+j]=1;
						ok=1;
					}
				}
			}
			if(!ok){
				if((a[1]%a[2]==0&&a[1]%a[3]==0&&a[1]>=a[2]&&a[1]>=a[3]) || (a[2]%a[1]==0&&a[2]%a[3]==0&&a[2]>=a[1]&&a[2]>=a[3]) || (a[3]%a[1]==0&&a[3]%a[2]==0&&a[3]>=a[1]&&a[3]>=a[2])){
					ans=1;
				}
				else ans=3;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
