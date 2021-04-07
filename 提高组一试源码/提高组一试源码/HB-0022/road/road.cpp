#include <bits/stdc++.h>
using namespace std;
const int N =100005;
long long  a[N],ans=0,n;

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sort(a+1,a+n+1,cmp);
		if(a[i]!=0){
		a[i]--;
		ans++;	
		}
		if((a[i]>0)&&(a[i-1]>0)&&(a[i+1]>0)){
			a[i]--;
			a[i-1]--;
			a[i+1]--;
			ans++;
		}
		if((a[i]>0)&&(a[i-1]=0)&&(a[i+1]=0)){
			a[i]--;
			ans++;
		}
			if((a[i]>0)&&(a[i-1]>0)&&(a[i+1]=0)){
			a[i]--;
			a[i-1]--;
			ans++;
		}
			if((a[i]>0)&&(a[i-1]=0)&&(a[i+1]>0)){
			a[i]--;
			a[i+1]--;
			ans++;
		}
		else if(a[n]>0){
			a[n]--;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
