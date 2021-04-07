#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int inf=100005;
int n;
int a[100005],minv=inf,sum;
void work(int x,int y,int z){
	for(register int i=x;i<=y;i++){
		a[i]-=z;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		minv=min(minv,a[i]);
	}
	sum+=minv;
	for(register int i=1;i<=n;i++){
		a[i]-=minv;
	}
	while(1){
		int k=0;
		int mip=inf,l=0;
		for(register int i=1;i<=n;i++){
			int w=0;
			l=i;
			while(a[i]>0){
				mip=min(mip,a[i]);
				i++;
				k=1;w=1;
			}
			if(w==0){
				continue;
			}
			work(l,i-1,mip);
			sum+=mip;
			mip=inf;
		}
		if(k==0)
			break;
	}
	printf("%d",sum);
	return 0;
}
