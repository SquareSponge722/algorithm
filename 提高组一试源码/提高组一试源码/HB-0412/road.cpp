#include<iostream>
#include<cstdio>
using namespace std;

int n;
int d[100001];
int day=0;
void di(int,int);
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	di(1,n);
	cout<<day<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


void di(int l,int r)
{
	int mid=r;
	for(int i=l;i<=r;i++)
	{
		d[i]--;
	}
	day++;
	for(int j=l;j<=r;j++)
	if(d[j]==0)
	{
		mid=j;
		break;
	}
	if(d[mid]!=0) di(l,r);
	else
	{
		if(mid-1>l) di(l,mid-1);
		if(mid+1<r) di(mid+1,r);
	}
}
