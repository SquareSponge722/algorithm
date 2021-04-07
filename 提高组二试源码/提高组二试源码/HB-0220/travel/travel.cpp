#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5005;
int u[N],v[N],mi[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false); 
    int n,m,p1=5006,z=2,i; 
	cin>>n>>m;
	for (i=1;i<=m;i++) cin>>u[i]>>v[i]; 
    for (i=1;i<=n;i++){
		if (z<=n){
	        mi[1]=1;
            for (int o=1;o<m;o++){
			    mi[0-o]==0;
                if (u[i]==mi[z-1]){
				    if (mi[z]!=mi[z-o]){
				    	mi[z]=v[i];
				        if (mi[z]<p1) {
				    	    p1=mi[z];
			    	        mi[z]=p1;
			    	        p1=5006;
					    }
				        z++;
					}//找mi，去重 
			    }
			    if (u[i]==mi[z-1]){
				    if (mi[z]!=mi[z-o]){
				    	mi[z]=v[i];
				        if (mi[z]<p1) {
				    	    p1=mi[z];
			    	        mi[z]=p1;
			    	        p1=5006;
					    }
				        z++;
					}//同上
			    } 
		    }
		}
	}
//	cout<<mi[1]<<" ";
	for (int i=1;i<=n;i++) 
	cout<<mi[i]<<" ";
    return 0;
}
