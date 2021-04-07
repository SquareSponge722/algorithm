#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d=0,b[100001],i,m1,m2;
	b[0]=0;
	scanf("%d",&n);
	b[n+1]=0;
	for(i=1;i<=n;i++)
	  scanf("%d",&b[i]);
	while(m1!=n){
		
	 
	for(i=0;i<=n&&b[i]==0;){
	    i++;
		m1=i;
	}
	for(i=m1;i<=n&&b[i]!=0;){
		i++;
		m2=i;
	}
	for(i=m1;i<m2;i++){
		b[i]--;
	}
	d++;
	}
	cout<<d;
	return 0;
}
