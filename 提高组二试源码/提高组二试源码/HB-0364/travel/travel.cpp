#include<bits/stdc++.h>
using namespace std;
int n,m;
int k[5001],d[5001];
int y[5001]={0};
struct lj{
	int u,v;
}a[5001];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d%d",&a[i].u,&a[i].v);
    k[1]=1;
    for (int i=1;i<n;i++){
    	k[i+1]=a[i].v;
	}
	for (int i=1;i<=n;i++){
		y[k[i]]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (y[k[i]]>1&&y[j]==0){
				k[i]=j;
				y[j]++;
			}
		}
	}
	k[n]=n;
    for (int i=1;i<n;i++) printf("%d ",k[i]);
    printf("%d\n",k[n]);
	return 0;
}
