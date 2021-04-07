#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int T,n,h[N];

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool cmp(int p,int q){
	return p<q;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	int m;
	while(T--){
		scanf("%d",&n);
		if(n==2){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==1||y==1) m=1;
			else if(gcd(x,y)==1) m=2;
			 	else m=1; 
		}
		if(n==3){
			for(int i=1;i<=n;i++)
				scanf("%d",h+i);
			sort(h+1,h+n+1,cmp);
			bool ok=0;
			if(gcd(h[1],h[2])==1){
				for(int j=0;h[1]*j<=h[3];j++)
					if((h[3]-h[1]*j)%h[2]==0){
						ok=1;
						break;
					}
				if(ok) m=2;
				else m=3;
			}
			else{
				int u=gcd(h[1],h[2]);
				if(h[3]%u==0) m=1;
				else m=2;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
