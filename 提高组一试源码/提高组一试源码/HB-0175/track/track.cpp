#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("track.in","r",stdin);
	freopen( "track.out","w",stdout);
	int n,d,m[100008];
	int ans=0;
	int maxn=0;
	int a=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>d;
	m[i]=d;
	maxn=max(maxn,d);
}
	for(int i=1;i<=maxn*n;i++){
	if(m[a]>0&&a<=n){
		m[a]--;a++;
	}
	else if(a>n){
		a=1;
		for(int k=1;k<=n;k++){
			a++;
			if(m[a]>0){
				ans++;a=1;
				break;
			}
		}
	}
	else  {
		for(int k=1;k<=n;k++){
			a++;
			if(m[a]>0){
				ans++;
				break;
			}
		}	
	}
	}
cout<<ans;
}


