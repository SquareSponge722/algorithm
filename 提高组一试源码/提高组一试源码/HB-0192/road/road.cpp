#include<bits/stdc++.h>
using namespace std;
int d[100010],n;
long long s;
void sc()
{
	int l,r,k;
	for(l=1;l<=n;l++)
	{
		if(d[l]!=0)
		{
			for(r=l;r<=n;r++)
		{
			if(d[r]==0) break;
		}
			if(r==n) r=n;
			for(k=l;k<=r-1;k++)
			d[k]--;
			s++;
			l=r-1;
		}
	}
}
int main()
{
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int max;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	int i=1;
	for(int j=1;j<=n-1;j++)
	if(d[i]<d[j]) i=j;
	max=d[i];
	for(int i=1;i<=max;i++)
	sc();
	cout<<s;
	return 0;
}
