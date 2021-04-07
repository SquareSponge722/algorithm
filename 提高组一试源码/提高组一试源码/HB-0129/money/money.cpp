#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,m,i,a[10001]={0},b[10001]={0};  
	int  u,v,w,x,y,z;
	cin>>T;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i]; 
	cin>>m;
    for(i=1;i<=m;i++)
	cin>>b[i];
	w=a[1]*a[2]-a[1]-a[2];
	x=a[1]*a[3]-a[1]-a[2];
	y=b[1]*b[2]-b[1]-b[2];
	z=b[1]*b[3]-b[1]-b[3];
	u=b[2]*b[3]-b[2]-b[3];
	v=a[2]*a[3]-a[2]-b[3];
	if(w==x&&w==v) cout<<2;
	if(y==z&&y==u) cout<<2;
	 return 0;
}
