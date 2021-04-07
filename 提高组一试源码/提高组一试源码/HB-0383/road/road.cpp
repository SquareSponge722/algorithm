#include<iostream>
#include<cstring>
using namespace std;
int n,d[100001],c[100001],days;
void fix(int l,int r,int x)
{
	if(c[r]==0||r==x)
	{
		days++;
		for(int i=l;i<=r;i++)
		{
			if(c[i]>0) c[i]--;
			for(int j=l;j<=i;j++)
				if(c[j]>0) fix(j,i,r);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		c[i]=d[i];
		fix(1,i,n);
		memset(d,0,sizeof(d));
	}
	cout<<days;
	return 0;
}
