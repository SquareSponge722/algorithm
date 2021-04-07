#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
6
4 3 2 5 3 5

10
100 50 250 650 400 300 350 150 200 700
*/
const int infn=999999999;
int n,a[100001]={0},ans=0,minn;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int s=1,e,flag=0,tt=0;
	while(1){
		flag=0,tt=0,minn=infn;
		for(int i=1;i<=n;i++){
			if(a[i]!=0 && flag==0){
				s=i;
				flag=1;
			}
			if(a[i+1]==0 && flag==1){
				e=i;
				break;
			}
		}
		for(int i=s;i<=e;i++){
			if(a[i]<minn) minn=a[i];
		}
		for(int i=s;i<=e;++i){
			a[i]-=minn;
		}
		ans+=minn;
		for(int i=1;i<=n;i++){
			if(a[i]!=0) tt=1;
		}
		if(tt==0) break;
	}
	printf("%d",ans);
	return 0;
}
