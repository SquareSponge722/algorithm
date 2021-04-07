#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],b[N];
int v[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<2*m;i++){
		cin>>a[i];
		v[i]=1;
	} 
	for(int i=0;i<2*m;i++){
		for(int j=i+1;j<2*m;j++)
			if(a[i]==a[j]) v[i]++;	
			if(v[i]>=3){
				for(int k=0;k<n;k++)
						b[k]=a[i];
 							for(int x=n;x>i;x--)
								for(int k=0;k<n;k++)
								if(b[i]==a[i]&&b[x]>a[x])  b[k]=a[i];
			}
				
		}
			for(int k=0;k<n;k++)
	cout<<b[k]<<" ";
	cout<<endl;
	return 0;
	}
