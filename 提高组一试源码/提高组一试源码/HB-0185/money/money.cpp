#include<bits/stdc++.h>
using namespace std;
int t;
bool pd(int a,int b,int c)
{
	for(int i=1;b*i<=a;i++)
	for(int j=1;c*j<=a;j++)
	if(b*i+c*j==a)return true;
	return false;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t) {
		t--;
		int n;
		scanf("%d",&n);
		int ans=n,e=0,f=0;
		bool ok;
		long long a[n+1],b[n+1],c[n+1];
		for(int i=1; i<=n; i++)scanf("%d",&a[i]);
		for(int i=1; i<=n; i++) {
			ok=0;
			for(int j=1; j<=n; j++) {
				if(i==j)continue;
				if(a[i]%a[j]==0) {
					ok=1;
					break;
				}
			}
			if(ok)continue;
			b[++e]=a[i];
		}
		for(int i=1; i<=e; i++)
		{
			ok=0;
			for(int j=1; j<=e; j++)
			{
				if(i==j)continue;
				for(int k=1; k<=e; k++) 
				{
					if(i==j||k==i||j==k||a[i]<a[j]+a[k])continue;
					if(!(a[i]%a[j])||!(a[i]%a[k])||pd(a[i],a[j],a[k]))
					{
						ok=1;
						break;
					}
				}
				if(ok)break;
			}
			if(ok)continue;
			f++;
		}
		printf("%ld\n",f);
	}
}
