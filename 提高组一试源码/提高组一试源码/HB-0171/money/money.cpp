#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define rg register

using namespace std;

const int N=110;
int n;
int main(){

	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		int m,a[N];
		scanf("%d",&m);
		if(m==2){
			for(rg int i=1;i<=m;i++)scanf("%d",a[i]);
			if(a[1]%a[2]==0||a[2]%a[1]==0)cout<<1<<endl;
			else cout<<2<<endl;
		}
		if(m==3){
			for(rg int i=1;i<=m;i++)scanf("%d",&a[i]);
			sort(a+1,a+1+m);
			if(a[3]==a[1]+a[2]){
				if(a[2]%a[1]==0)cout<<1<<endl;
				else cout<<2<<endl;
			}
			else{
				if(a[2]%a[1]==0&&a[3]%a[1]==0)cout<<1<<endl;
				else if(a[2]%a[1]==0)cout<<2<<endl;
				else if(a[3]%a[2]==0)cout<<2<<endl;
				else if(a[3]%a[1]==0)cout<<2<<endl;
				else cout<<3<<endl;
			}
		}
	}
	return 0;

}
