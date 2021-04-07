#include<bits/stdc++.h>
using namespace std;
int a[101],sum[101][2501],x[101];
bool y[101];
bool search0(int z){
	if(!y[2]) 
      for(int i=1;i<=x[1];i++)
	     for(int j=1;j<=x[2];j++)
	       if(sum[1][i]+sum[2][j]==a[z]) return true;
	if(y[2]) if(!(a[3]%a[1])) return true;
	return false;
}


bool judge(int i){
	if(i==2) 
	  if(!(a[2]%a[1])) return true;
	     else return false;
	for(int j=1;j<i;j++){
	    if(y[j]) continue;
		x[j]=1;
		sum[j][x[j]]=a[j];	
	    while(sum[j][x[j]]<=a[i])
	         if(!sum[j][x[j]+1])
		       sum[j][x[j]+1]=sum[j][x[j]]*a[j],x[j]++;
		}
	if(i==3)
    return search0(i);
   
}


int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio;
	int t,n,ans=0;
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;ans=n;
		for(int i=1;i<=n;i++)
		    cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]==1) {
		cout<<"1"<<endl;continue;
		}
		if(n>3) cout<<(n-2);
		else {
		for(int j=2;j<=n;j++)
		   if(judge(j)) {
		   ans--; y[j]=true;
		   }
		cout<<ans<<endl;
		memset(a,0,sizeof(a));memset(y,0,sizeof(y));
		for(int i=0;i<=n;i++)
		    for(int j=1;j<=x[i]+1;j++)
			   sum[i][j]=0;
	   n=0;ans=0;
			}
	}
	return 0;
}
