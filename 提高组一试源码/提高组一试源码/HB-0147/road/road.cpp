#include<bits/stdc++.h>
using namespace std;

int n,d[100005] = {0},high[100005],low[100005],t,j=1,k=1,suml,sumh;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n+1;i++){
		cin>>d[i];}
	for(int i=1;i<=n+1;i++){
		if(d[i]<=d[i-1]&&d[i]<=d[i+1]) low[j++] = d[i];
		if(d[i]>=d[i-1]&&d[i]>=d[i+1]) high[k++] = d[i];
	}
	for(int x=1;x<=j;x++)
	suml += low[x];
	for(int x=1;x<=k;x++)
	sumh += high[x];
	
	t = sumh-suml;
	cout<<t<<endl;
	return 0;
}

