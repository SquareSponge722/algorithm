#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=0;
	int n;
	int a[100001]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int s=0;
	int l,r;
	bool f=0;
	bool q=0,w=0;
	while(q==0){
		s=0,l=0,r=0;
		f=0,w=0;
	for(int i=1;i<=n+1;i++){
		if(f==1&&w==1) break;
		if(w==1) continue;
		if(a[i]==0) {
			if(f==1&&l<=i-1) {r=i-1;
			w=1;}
		}
		if(f==1) continue;
		if(a[i]!=0) {
			l=i;
			f=1;
		}
		
	}
	for(int i=l;i<=r;i++){
		a[i]--;
	}
	t++;
	for(int i=1;i<=n;i++){
		if(a[i]==0) s++;
		if(s==n) q=1;
	}
}
printf("%d",t);
	return 0;
}
