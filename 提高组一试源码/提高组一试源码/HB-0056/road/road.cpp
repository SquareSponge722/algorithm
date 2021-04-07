#include<bits/stdc++.h>
using namespace std;
int n,ans,d[300000],v[300000],b[300000],sum,u,maxx;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
	}
	ans=0;
	for(int i=1; i<=n; i++) {
		maxx=21474836;
		if(sum==n)break;
		for(int j=1; j<=n; j++) {
			if(d[j]!=0&&maxx>d[j]) {
				maxx=d[j];
				u=j;
			}
		}
		ans+=maxx;
		d[u]=0;
		sum++;
		for(int j=u+1; j<=n; j++) { 
			if(d[j]>maxx)d[j]=d[j]-maxx;
		else	if(d[j]==maxx) {
				d[j]=0;
				sum++;
			} 
		else	if(d[j]<maxx) break;
		}
		for(int j=u-1; j>=1; j--) {
			if(d[j]>maxx)d[j]=d[j]-maxx;
		else if(d[j]==maxx) {
				d[j]=0;
				sum++;
			} 
			else if(d[j]<maxx) break;
		}
	}
	printf("%d",ans);
	return 0;
}
