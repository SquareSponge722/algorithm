//I WA NOIP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 100007
using namespace std;
int n,d[maxn],ans=0;
//int f[maxn][maxn];
//f[i][j]Ìî³ä[i£¬j]×î¶Ì£»
//f[i][j]=min(f[i+1][j]+b[i],f[i][j-1]+b[j])
int main() {
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	scanf("%d",&n);
	for(int i=1; i<=n; i++){scanf("%d",&d[i]);
	if(i==1)ans=d[i];
	if(i>1){
	if(d[i]>d[i-1])ans+=(d[i]-d[i-1]);
	}
	//f[i][i]=d[i];
	}
	printf("%d",ans);
	return 0;
}
/*	for(int i=n; i>0; i--) {
		for(int j=i; j<=n; j++) {
			if(d[i]<d[i+1]&&d[j]<d[j-1])
			    f[i][j]=min(f[i+1][j],f[i][j-1]);
			else if(d[i]<d[i+1]&&d[j]>=d[j-1])
			    f[i][j]=min(f[i+1][j],f[i][j-1]+d[j]-d[j-1]);
			else if(d[i]>=d[i+1]&&d[j]<d[j-1])
			    f[i][j]=min(f[i+1][j]+d[i]-d[i+1],f[i][j-1]);
			else if(d[i]>=d[i+1]&&d[j]>=d[j-1])
			    f[i][j]=min(f[i+1][j]+d[i]-d[i+1],f[i][j-1]+d[j]-d[j-1]);
		}
	}
    printf("%d",f[1][n]);
	È¥ÄãµÄdp°É*/
    
