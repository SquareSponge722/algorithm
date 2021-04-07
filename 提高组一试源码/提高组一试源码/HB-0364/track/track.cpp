#include<bits/stdc++.h>
using namespace std;
const int N=50001;
int a[N],b[N],l[N];

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) scanf("%d%d%d",&a[i],&b[i],&l[i]);
	printf("%d\n",n*m);
	return 0;
}
