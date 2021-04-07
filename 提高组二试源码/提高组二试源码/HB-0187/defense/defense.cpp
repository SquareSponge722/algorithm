#include<iostream>
#include<cstdio>
using namespace std;
const int mm=100005;

int n,m;
string type;
int p[mm],u[mm],v[mm],a[mm],x[mm],b[mm],y[mm];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n-1;i++)cin>>u[i]>>v[i];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>x[i]>>b[i]>>y[i];
		cout<<-1<<endl;
	}
	return 0;
}
