#include<bits/stdc++.h>
using namespace std;
int a[105];
bool b[105];

bool can(int i,int j,int k){
	int cnt=k/j;
	for(int c=1;c<=cnt;c++){
		if((k-c*j)%i==0)return true;
	}
	return false;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
	    memset(b,0,sizeof(b));
		int w;
		cin>>n;
	
		for(int i=1;i<=n;i++)cin>>a[i];
	
		sort(a+1,a+n+1);
	
		if(a[1]==1){cout<<1<<endl;continue;}
		int k;	
		for(int i=2;i<=n;i++)
			if(a[i]%a[1]!=0)
			  {w=a[1]*a[i]-a[i]-a[1];k=i;break;}
			else b[i]=1;
	    
		for(int i=2;i<=n;i++)if(a[i]>w&&i!=k)b[i]=1;
	
		for(int i=1;i<n;i++)
		   for(int j=i+1;j<=n;j++){
		   	if(a[j]%a[i]==0&&b[j]==0&&b[i]==0)b[j]=1;
		   }
		for(int i=1;i<=n-2;i++)
		   for(int j=i+1;j<=n-1;j++)
		      for(int k=j+1;k<=n;k++)
		         if(can(a[i],a[j],a[k])==true&&b[i]==0&&b[j]==0&&b[k]==0){b[k]=1;}
		int ans=0;
		for(int i=1;i<=n;i++)if(b[i]==0)ans++;
		cout<<ans<<endl;
	}
	return 0;
}
