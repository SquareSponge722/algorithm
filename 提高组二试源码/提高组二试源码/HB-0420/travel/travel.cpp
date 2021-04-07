#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	int a[5000];
	int b[5000];
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	for(int i=0; i<1; i++) {
		printf("%d ",a[i]);

	}
	for(int i=0; i<m; i++) {
		if(i%2==0) {
			printf("%d ",b[i]);
		}

		if(b[i+1]-b[i]==1) {
			printf("%d ",b[i+1]);
		}
		if(b[i]-b[i+1]==1) {
			printf("%d ",b[i+1]);
		} else if(b[i]-a[i+1]==1&&a[i+1]!=a[i]) {
			printf("%d ",a[i+1]);
		}
		else if(a[i+1]-b[i]==1&&a[1+1]!=a[i]) {
			printf("%d ",a[i+1]);
		}

	}
	return 0;
}
//感谢老师和电脑批改！！！ 
