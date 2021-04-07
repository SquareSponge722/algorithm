#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn]={0},day;
void check(int m,int n)
{
	for(int i=m;i<=n;i++)
	{
		if(a[i]==0)
		{
			m=i+1;
			check(m,n);
		}
		if(a[i]>0)
		{
			a[i]=a[i]-1;
			if(a[i+1]==0)
			{
				day++;
				check(m,n);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,b;
	b=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	check(b,n);
	cout<<day;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

