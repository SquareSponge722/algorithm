#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T;
int n,a[N];
int ans=0;

int gcd(int x,int y){
	if(y==0) {
		return x;
	}
	else gcd(y,x%y);
	
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		n=0;
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==2) {
			sort(a+1,a+n+1);
			if(a[1]==1) ans=1;
			else if(gcd(a[1],a[2])==a[1] || gcd(a[1],a[2])==a[2]) ans=1;
			else ans=2;
		}
		if(n==3){
			sort(a+1,a+n+1);
			if(a[1]==1) ans=1;
			else{
			int	y=gcd(gcd(a[1],a[2]),a[3]);
			int x=gcd(a[1],a[2]);
			int z=gcd(a[2],a[3]);
			int m=gcd(a[1],a[3]);
						
			if(y==a[1] ) ans=1;
			if(x==a[1] && y!=a[1] ) ans=2;	
			if(z==a[2] && y!=a[1] ) ans=2;	
			if(m==a[1] && y!=a[1] ) ans=2;	
			else ans=3;						
				}
				
			}
			else {
				sort(a+1,a+n+1);
				int x=gcd(a[1],a[2]);
				for(int i=2;i<n;i++){
					x=gcd(x,a[i+1]);
				}
				if(x==1) ans=n;
			}
			printf("%d\n",ans);
		}
	return 0;	
	}	
	
