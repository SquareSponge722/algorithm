#include<bits/stdc++.h>
using namespace std;
int a[25005],f1[25005],f2[25005],ans[100];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	int t,n;a[0]=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;

		if(n==1){
				cout<<1;
				return 0;	}
		for(int j=1;j<=n;j++){
			cin>>a[j];	}

		sort(a,a+n+1);	
		
	for(int j=n;j>1;j--)	{
		int o=0;
		for(int k=1;k<j;k++)
		{ 	
			if(a[j]%a[k]==0)
			   { n--;
			   break;}
			else{f1[j]=a[j]%a[k];
				
			for(int p=1;p<j;p++){
		        if(f1[j]%a[p]==0 ) {
						n--;o++;
						break;	}
				if(f1[j]%a[p]!=0){
					f2[j]=f1[j]%a[p];
					for(int x=1;x<j;x++)
					  if(f2[j]%a[x]==0){
					  	n--;o++;
					  	break;
					  }  
				  }	}	
			   	if(o!=0) break;
			    
							
					}
		
			}	
	   }		
	 
		ans[i]=n;
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}
