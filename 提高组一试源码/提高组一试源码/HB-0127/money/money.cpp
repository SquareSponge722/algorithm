#include<bits/stdc++.h>
using namespace std;
int T,n,fw,w,q,ans;
long long zy;
int A[105];
bool B[105],ok;

int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);	
	scanf("%d",&T);
	while (T--){
		w=1;
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			B[i]=1;
			scanf("%d",&A[i]);
		}
		fw=A[2];
		sort(A+1,A+n+1);
		if (A[1]==1||n==1) {
			printf("%d\n",1);
			continue;
		}
		for (int i=2;i<=n;i++){
			if (gcd(A[1],A[i])==1){
				if (!ok) {
					if (fw<A[1]*A[i]-A[1]-A[i])
						fw=A[1]*A[i]-A[1]-A[i];
					ok=1;
					break;
				}
			}
			else B[i]=0;
		}
		for (int i=1;i<=n;i++){
			if (i==1) w=0;
			if (A[i]>fw) break;
			w++;
		}
		for (int i=w;i>1;i--){
			q=A[i]%A[i-1];
			for (int j=1;j<i-1;j++){
				if (q==0) {
					B[i]=0;
					break;
				}
				q=q%A[j];
			}
		}
		for (int i=1;i<=w;i++){
			if (B[i]==1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
