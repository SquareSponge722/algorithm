#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int ans;
int a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	while(1){
	if(a[0]!=0) {
			for(int i=0;i<n;i++) {
				if(i==n-1&&a[i]>0) {
					a[i]-=1;
					ans++;
					break;
				}
				if(!a[i]) {
					ans++;
					break;
				}
				if(a[i]) {
					a[i]-=1;
				}
			}
		}
		if(!a[0]) {
			for(int i=0;i<n;i++) {
				if(i==n-1&&a[i]==0) {
					printf("%d",ans);
					return 0;
				}
				if(a[i]) {
					for(int j=i;j<n;j++) {
						if(j==n-1&&a[j]>0) {
							a[j]-=1;
							ans++;
							break;
						}
						if(!a[j]) {
							ans++;
							break;
						}
						if(a[j]) a[j]-=1;
					}        
				}
			}
		}
	}
	return 0;
}
