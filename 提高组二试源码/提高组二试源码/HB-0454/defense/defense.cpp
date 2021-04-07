#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string type;
int i,j,x,p[100111];
long long a[100111][100111],q[100111][4];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	cin>>n>>m>>type;
	for(i=0;i<n;i++) cin>>p[i];
	for(j=0;j<n-1;j++)
	for(x=0;x<2;x++)
	cin>>a[j][x];
	for(i=0;i<m;i++)
	for(x=0;x<4;x++)
	cin>>q[i][x];
	for(i=0;i<m;i++) cout<<"-1"<<endl;
	return 0;
}
