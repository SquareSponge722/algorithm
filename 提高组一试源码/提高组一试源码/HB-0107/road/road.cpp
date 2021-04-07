#include<bits/stdc++.h>
using namespace std;
struct node {
	int list,depth;
};
node a[100005];
int m,n;
int day,duan=1,cnt;
bool pd[100005];
bool cmp(node x,node y) {
	if(x.depth==y.depth) return x.list<y.list;
	return x.depth<y.depth;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(register int i=2; i<=n+1; i++) {
		scanf("%d",&a[i].depth);
		a[i].list=i;
	}
	sort(a+2,a+n+2,cmp);
//	for(register int i=2; i<=n+1; i++) cout<<a[i].depth<<" ";
//	cout<<endl;
//	for(register int i=2; i<=n+1; i++) cout<<i<<" ";
//	cout<<endl;
	pd[0]=pd[1]=pd[n+2]=pd[n+3]=true;
	for(register int i=2; i<=n+1; i++) {
		if(a[i].depth==a[i-1].depth) {
			pd[a[i].list]=true;
			if(pd[a[i].list-1]==false&&pd[a[i].list+1]==false) {
				duan++;
//				cout<<"  "<<duan<<"   "<<i<<endl;
			}
		} else {
			duan=duan-cnt;
			day=day+duan*(a[i].depth-a[i-1].depth);
//			cout<<day<<" "<<duan<<" "<<a[i].depth-a[i-1].depth<<" "<<i<<endl;

			cnt=0;
			pd[a[i].list]=true;
			if(pd[a[i].list-1]==false&&pd[a[i].list+1]==false) {
				duan++;
			}
		}
		if(pd[a[i].list-1]==true&&pd[a[i].list+1]==true) cnt++;
	}
	printf("%d",day);
//cout<<sizeof(a)/1024/1024;
	return 0;
}
/*
10
1 2 3 2 1 0 1 2 1 0

*/
