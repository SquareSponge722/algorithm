#include<bits/stdc++.h>
using namespace std;
int n,f=0,a[100005],ans = 0;

bool empty(){
	for(int i=0;i<n;i++)
		if (a[i]>0) return false;
	return true;
}

bool full(){
	for(int i=0;i<n;i++)
		if (a[i]==0) return false;
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n+5;i++)
		a[i] = 10005;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(!a[i]) f++;
	}
	while(!empty()){
		for(int i=0;i<n;i++)
			a[i]--;
		if(full()) ans++;
		else {
			for(int i=0;i<n;i++){
				if(a[i]==0&&a[i-1]<=0&&i!=0)continue;
				else if(a[i]==0&&a[i+1]<=0) continue;
				else if(a[i]==0){
					f++;
					ans += f;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
		
}
