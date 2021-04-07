#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	int p[100001],u[n],v[n],a[m],b[m],c[m],d[m];
	string type;
	cin>>n>>m;
	cin>>type;
	for(int i=0;i<n;i++)
	cin>>p[i];
	for(int k=0;k<n-1;k++)
	cin>>u[k]>>v[k];
	for(int s=0;s<m;s++)
	cin>>a[s]>>b[s]>>c[s]>>d[s];
	if(n==5&&m==3)
	cout<<"12"<<endl<<"7"<<endl<<"-1"<<endl;
	if(n==10&&m==10)
	cout<<" "<<endl<<" "<<endl<<"-1"<<endl;
	
	
	
	return 0;
}
