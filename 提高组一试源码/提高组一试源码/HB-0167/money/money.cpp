# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
struct money
{
	int n;
	int a[150];
	int m;
	int b[150];
}x[50];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,i,j,q,p;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>x[i].n;
		for(j=0;j<x[i].n;j++)
		{
			cin>>x[i].a[j];
			x[i].b[j]=x[i].a[j];
		}
		sort(x[i].b,x[i].b+x[i].n);
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<x[i].n;j++)
			for(q=0;q<x[i].n;q++)
			{
				if(x[i].a[q]%x[i].b[0]==0) x[i].m=1;
				else x[i].m=x[i].n;
			}
	}
	for(i=0;i<t;i++)
		cout<<x[i].m<<endl;
	return 0;
}
