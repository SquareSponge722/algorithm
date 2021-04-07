#include<bits/stdc++.h>
using namespace std;
int n,a[110],ans,t;
bool b[110],ok;
bool cmp(int a,int b) {
	return a>b;
}
int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
bool pd(int a,int b,int c) {
	if(a<b)swap(a,b);
	for(int i=1; i*a<=c; i++)
		if((c-i*a)%b==0)return true;
	return false;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int p=1; p<=t; p++) {
		ok=0;
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		ans=n;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			if(a[i]==1) {
				printf("1\n");
				ok=1;
			}
		}
		if(ok)continue;
		sort(a+1,a+1+n,cmp);
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(a[i]%a[j]==0)b[i]=1,ans--;
		for(int i=1; i<=n; i++) {
			if(b[i])continue;
			for(int j=i+1; j<=n; j++) {
				if(b[j]||gcd(a[i],a[j])!=1)continue;
				int sum=a[i]*a[j]-a[i]-a[j];
				for(int k=1; k<=n; k++) {
					if(b[k]||k==i||k==j)continue;
					if(a[k]>sum)b[k]=1,ans--;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(b[i])continue;
			for(int j=i+1; j<=n; j++) {
				if(b[j])continue;
				for(int k=1; k<=n; k++) {
					if(b[k]||k==i||k==j)continue;
					if(pd(a[i],a[j],a[k]))b[k]=1,ans--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
