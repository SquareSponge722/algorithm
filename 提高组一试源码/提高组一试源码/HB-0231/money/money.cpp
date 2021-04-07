#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
const long long inf = INT_MAX;
int n;
long long a[maxn];
bool f[850005];
bool c[850005];
long long ans[maxn];
int tot;
int t;
long long M;
int mina,minb;
bool nic;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

bool check(int now){
	for (int i=now;i<=M;i++){
	    c[i] = c[i-now] | c[i];	
	}
	for (int i=now;i<=M;i++){
		if(f[i]!=c[i])return false;
	}
	return true;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&t);
	for (int zz=1;zz<=t;zz++){
		tot=0;M = inf;nic=false;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==1)nic=true;
		}
		if(n==1||nic){
			printf("1\n");continue;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if(gcd(a[i],a[j])==1){
					if(a[i]*a[j]-a[i]-a[j]==M){
						if(mina<=M&&minb<=M)continue;
						if(a[i]<=M&&a[j]<=M){
							mina = a[i],minb = a[j];
						}
						if(mina<=M||minb<=M)continue;
						else if(a[i]<=M||a[j]<=M){
							mina = a[i],minb = a[j];
						}
					}
					if(a[i]*a[j]-a[i]-a[j]<M){
						M = a[i]*a[j]-a[i]-a[j];
						mina = a[i],minb = a[j];
					}
					
				}
			}
		}
		if(M==inf){
			M = 25000;mina=minb=0;
		}
		for (int i=1;i<=M;i++){
			c[i]=f[i]=false;
		}
		sort(a+1,a+n+1);
	    f[0] = c[0] = true;
	    for (int k=1;k<=n;k++){
		    for (int i=a[k];i<=M;i++){
			    f[i] = f[i-a[k]] | f[i];
		    }
	    }
	    if(M<a[1]){
	    	printf("2\n");return 0;
		}
	    for (int k=1;k<=n;k++){
	    	if(!c[a[k]]){
	    		tot++;
	    		ans[tot] = a[k];
	    		if(check(a[k]))break;
			}
		}
		if(mina>M)tot++;
		if(minb>M)tot++;
		//for (int i=1;i<=tot;i++)cout<<ans[i]<<endl;
		printf("%d\n",tot);
	}
	
	
	return 0;
}
