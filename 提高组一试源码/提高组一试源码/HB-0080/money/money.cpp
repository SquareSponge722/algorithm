#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
const int MAXN = 107;
int a[MAXN];
int d[MAXN][MAXN];
int main(){
	freopen("money1.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans=n;
		for(int i=1;i<n;i++){
			//01 dp ... error
			memset(d,0,sizeof(d));
			bool sign=false;
			for(int j=0;j<i;j++){
				for(int k=0;k<=a[i];k++){
					d[j][k]=(j==0)?0:d[j-1][k];
					if(k>a[j])d[j][k]=max(d[j][k],d[j-1][k-a[j]]+a[j]);
					if(d[j][k]==a[i]){sign=true;break;}
				}
				if(sign){ans--;break;}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
