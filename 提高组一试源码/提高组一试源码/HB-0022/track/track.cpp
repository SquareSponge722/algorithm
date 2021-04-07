#include <bits/stdc++.h>
using namespace std;
const int N =50005;
long long n,m,f[N][N];

struct node{
	long long x,y,z;
}a[50005];

bool cmp(node g,node k){
	return g.z<k.z;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-1;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			sort(a[i].z+1,a[i].z+n+1,cmp);
			f[i][j]+=a[j].z;
			if(f[i][j]>0){
				f[i][j]=min(f[i][j],f[i-1][j]);
			}
			cout<<f[i][j]<<endl;
			return 0;
		}
}
