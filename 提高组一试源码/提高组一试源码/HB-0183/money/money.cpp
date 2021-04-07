#include<bits/stdc++.h>
#define N 105
using namespace std;
int t,n,a[N];
bool prime[N];
void read(int &x){
	int t = 1;x=0;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') t = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+ch^48;ch = getchar();}
	x*=t;
}

void init(){
	memset(prime,true,sizeof(prime));
	prime[1] = prime[2] = true;
	for(int i=2;i<=100;i++)
		for(int j=2;j<=50;j++){
			prime[i*j] = false;
			if(i*j>100) continue;
		}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	init();
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]);
		if(prime[n] == true) printf("%d\n",n);
		else {
			for(int i=2;i<=n;i++){
				if(n%i==0) 
				printf("%d\n",i);
				break;
			}
		}	
	}
	return 0;
}
