#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 101;
int T,n,a[N],ans;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			ans=n;
			if(n==2){
				if(gcd(a[1],a[2])==a[1]||a[1]==1) ans=1;
				else ans=2;
			}	
			if(n==3){
				if(a[1]==1) ans=1;
				if(a[1]==a[2]&&a[2]==a[3]) ans=1;
				if(gcd(a[1],a[2])==a[1]&&gcd(a[1],a[3])==a[1]) ans=1;
				else {
					if(gcd(a[1],a[2])==a[1]||gcd(a[1],a[3])==a[1]||gcd(a[2],a[3])==a[2]) ans=ans-1;
					if((a[1]+a[2])==a[3]) ans=ans-1;
					else ans=3;
				}
			}
			if(n==4){
				if(a[1]==1) ans=1;
				if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]) ans=1;
				else {
					if(gcd(a[1],a[2])==a[1]||gcd(a[1],a[3])==a[1]||gcd(a[1],a[4])==a[1]||gcd(a[2],a[3])==a[2]
					||gcd(a[2],a[4])==a[2]||gcd(a[3],a[4])==a[3]) ans=ans-1;
					if(a[1]+a[2]==a[3]||a[1]+a[2]==a[4]||a[3]+a[2]==a[4]) ans=ans-1;
					if((a[1]+a[2]+a[3])==a[4]) ans=ans-1; 
					else ans=4;
				}
			}
			if(n==5){
				if(a[1]==1) ans=1;
				if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]) ans=1;
				else{
					if(gcd(a[1],a[2])==a[1]||gcd(a[1],a[3])==a[1]||gcd(a[1],a[4])==a[1]||gcd(a[1],a[5])==a[1]
					||gcd(a[2],a[3])==a[2]||gcd(a[2],a[4])==a[2]||gcd(a[2],a[5])==a[2]||gcd(a[3],a[4])==a[3]
					||gcd(a[3],a[5])==a[3]) ans=ans-1;
					if(a[1]+a[2]==a[3]||a[1]+a[2]==a[4]||a[1]+a[2]==a[5]||a[3]+a[2]==a[4]||a[3]+a[2]==a[5]||a[3]+a[4]==a[5]) ans=ans-1;
					if((a[1]+a[2]+a[3]+a[4])==a[5]) ans=ans-1;  //?
					else ans=5;
				}
			}
			printf("%d\n",ans);
		}
	return 0;
}

//else {
//	for(int i=2;i<=n;i++){
//		int cnt=0;
//		for(int j=1;j<=n;j++){  	
//			if(a[j]%i==0) cnt++;  // gcd相同数的个数 
//		}
//		sum=max(cnt,sum);
//	}
