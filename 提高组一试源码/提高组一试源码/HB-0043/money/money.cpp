#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n;
int a[N];
int ans=0;
void sol1(){
	for(int i=1;i<=n;i++) sort(a,a+n);
	if((a[2]%a[1]==0)) ans=1;
	else ans=2;
}

void sol2(){
	ans=3;
	for(int i=1;i<=n;i++) sort(a,a+n);
	if((a[3]%a[2])==0) ans--;
	if((a[3]%a[1])==0)ans--;
	if((a[2]%a[1])==0)ans--;
	if((a[2]%a[1])==0 && (a[3]%a[1])==0) ans=1;
	if((a[3]%a[1])==0 && (a[3]%a[2])==0 && (a[2]%a[1])!=0) ans=2;
	if((a[3]%a[1])!=0 && (a[3]%a[2])!=0 && (a[2]%a[1])!=0)
		for(int i=1;i*a[1]<=a[3];i++)
			for(int j=1;j*a[2]<=a[3];j++)
				if(a[1]*i+a[2]*j==a[3]) ans=2;
}

void sol3(){
	ans=4;
	for(int i=1;i<=n;i++) sort(a,a+n);
	for(int i=1;i<n;i++)
		for(int j=2;i<j&&j<=n;j++){
			if((a[j]%a[i])==0) ans--;
			if(ans==0) ans=1;
		}
		
		
}

void sol4(){
	ans=n;
	for(int i=1;i<=n;i++) sort(a,a+n);
	for(int i=1;i<=n;i++)
		if(a[1]*a[2]<=a[i]) ans--;
		else {
			for(int i=1;i*a[1]<=a[1]*a[2];i++)
				for(int j=1;j*a[2]<=a[1]*a[2];j++)
					if(a[1]*i+a[2]*j==a[3]) ans--;
		}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==2) {
			sol1();
			printf("%d\n",ans);
			continue;
	}
		if(n==3){
			sol2();
			printf("%d\n",ans);
			continue;
	}
		if(n==4){
			sol3();
			printf("%d\n",ans);
			continue;
	}
		if(n<=13){
			sol4();
			printf("%d\n",ans);
			continue;
	}	
} 	
	return 0;
}
