#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,l,r,min,day,ycyz;
	int d[10005];
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&d[i]);
	}
	for(int i=0; i<n; i++) {
		if(d[i]<d[i+1]) {
			d[i+1]=d[i];
		}
		min=d[i];
	}
	for(int i=0; i<min; i++) {
		if(d[i]>0) {
			d[i]--;
			day++;
		}
	}
	for(int j=0; j<100000; j++) {
		for(int i=0; i<n; i++) {
			if(min=d[i]) {
				ycyz=i;
			}
		}
		for(int i=0; i<ycyz; i++) {
			if(d[i]>0) {
				d[i]--;
				day++;
			}
		}
		for(int i=n; i>ycyz; i--) {
			if(d[i]>0) {
				d[i]--;
				day++;
			}
		}
	}
	printf("%d",day);
	return 0;
}

//谢谢老师在百忙之中抽出时间查卷子 
