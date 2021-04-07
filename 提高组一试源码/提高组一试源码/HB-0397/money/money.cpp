#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int m[105];
int ans[105];
struct node{
	int num;
	bool note;
}a[105][50000];
int cmp(node x,node y) {
	return x.num<y.num;
}
int main(){
	//freopen("money.in","r",stdin);
	//freopen("money.out","w",stdout);
	for(int i=0;i<105;i++) {
		for(int g=0;g<25000;g++){
			a[i][g].note=1;
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m[i]);
		for(int g=0;g<m[i];g++) {
			scanf("%d",&a[i][g].num);
		}
	}
	for (int i=0;i<n;i++) {
		for(int j=0;j<m[i];j++) {
			a[i][j].note=1;
		}
		for (int j=0;j<m[i];j++) {
			sort(a,a+m[i],cmp);
			for(int k=j+1;k<n;k++) {
				int s=a[i][k].num%a[i][j].num;
				for(int h=0;h<m[i];h++) {
					if(s==a[i][h].num) a[i][k].note=0;
				}
			}	
		}
		for(int j=0;j<m[i];j++) {
			if(!a[i][j].note) m[i]--;
		}
	}
	for(int i=0;i<n;i++) {
		printf("%d\n",m[i]);
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
