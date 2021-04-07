#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxl=100001;
int n,a[maxl]={0},flag,day,p;
int i,j,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	flag=n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(flag>0)
	{
		for(i=1;i<=n;i++)
		{
			while(a[i]>0)
			{
				p=i;
				for(j=p;a[j]!=0;j++)
				{
					a[j]--;
					if(a[j]==0){flag--;}
				}
				day++;
			}
		}
	}
	cout<<day;
	return 0;
}
