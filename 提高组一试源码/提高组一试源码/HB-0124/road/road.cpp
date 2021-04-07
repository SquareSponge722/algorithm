#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
int a[100100];
bool pd;
long long cnt=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	bool le=false;
	pd=true;
	int p=1;	
	int now=0x3f3f3f;
	while(pd){
		pd=false;
		for(int i=p;i<=n;i++){
			if(a[i]!=0&&a[i-1]==0){
				p=i;
				l=i;
				pd=true;
				//cout<<i<<endl;
			}
			if(a[i]!=0){
				now=min(a[i],now);
			}
			if(a[i]!=0&&a[i+1]==0){
				r=i;
				cnt+=now;
				break;
			}
		}
		for(int i=l;i<=r;i++){
			a[i]-=now;
		}
		//cout<<l<<' '<<r<<' '<<now<<endl;
		now=0x3f3f3f;
	}
	cout<<cnt<<endl;
	return 0;
}
