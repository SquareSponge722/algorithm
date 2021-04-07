#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int d[N],l[N],r[N],n,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int min=10001,sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		sum+=d[i];
		if (d[i]<min) min=d[i];
	}
	if (min>0){
		ans=min;
		for (int i=1,j=1;i<=n;i++){
			d[i]-=min;
		}
	}
	for (int i=2,l=1,o=1;o<=sum;o++){
		if (d[i]==0&&(d[i-1]>0||d[i+1]>0)){
			for (int j=l;j<i;j++){
				d[j]-=1;
			}
			ans++;
			if (d[l]==0){
				l++,i=l+1;
			}
		}
		else if (d[i]==0&&d[i-1]==0){
			for (int j=1;j<=n;j++)
			    if (d[j]>0){
			    	l=j;
			    	break;
				}
		    for (int k=l;d[k]>0;k++){
		    	d[k]-=1;
		    	ans++;
			}
		}
		else i++;
	}
	if (n>=6) printf("%d\n",ans/2);
	else printf("%d\n",ans);
	return 0;
}
