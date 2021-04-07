#include<cstdio>
using namespace std;
const int N=105;
int T,n,a[N];
bool div(int x,int y){return !(a[x]%a[y]);}
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(register int i=1;i<=n;++i) scanf("%d",a+i);
		if(n==2){
			if(!(a[1]%a[2])||!(a[2]%a[1])) puts("1");
			else puts("2");
			continue;
		}
		if(n==3){
			if((div(1,2)&&(div(1,3)))||(div(2,1)&&div(2,3))||(div(3,1)&&div(3,2))) puts("1");
			else{
				int gcd1=gcd(a[1],a[2]),gcd2=gcd(a[2],a[3]),gcd3=gcd(a[3],a[1]);
				if(gcd1==gcd2&&gcd1==gcd3) puts("1");
				else if(gcd1!=1&&(!(gcd1%a[3])||!(a[3]%gcd1))) puts("2");
				else if(gcd2!=1&&(!(gcd2%a[1])||!(a[1]%gcd2))) puts("2");
				else if(gcd3!=1&&(!(gcd3%a[2])||!(a[2]%gcd3))) puts("2");
				else puts("3");
			}
			continue;
		}
		else printf("%d\n",n);
	}
	return 0;
}
