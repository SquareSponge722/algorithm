#include <bits/stdc++.h>
using namespace std;
int main() {
	int m,n,aj,bj,lj,XieXieLaoShi,GanXieLaoShi;
	int ycyz[1806];
	scanf("%d %d",&n,&m);
	for(int j=0; j<n-1; j++) {
		scanf("%d %d %d",&aj,&bj,&lj);
		ycyz[j]=aj+bj+lj;
	}
	for(int i=0; i<n-1; i++) {
		GanXieLaoShi+=ycyz[i];
	}
	XieXieLaoShi=GanXieLaoShi-53;
	printf("%d",XieXieLaoShi);
	return 0;
}
