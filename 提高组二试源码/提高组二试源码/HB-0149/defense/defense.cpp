#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	freopen("defense1.in","r",stdin);
	freopen("defense1.out","w",stdout);
	int n,m,w;
	string type;
	int p[100001],j[100001],a[100001];
	cin>>n>>m>>type;
	for(int i=1;i<=(2*(n-1));i++)
	{
	cin>>p[i];
	cin>>a[i];
    for(int k=1;k<=(4*m);k++)
	{
	cin>>j[k];
	if(j[k+1]==0&&j[k+3]==0&&a[i]==j[k]&&a[i+1]==j[k+2])
	cout<<"-1";
	else if(j[k+1]==0&&j[k+3]==0&&a[i]==j[k]&&a[i+1]!=j[k+2])
	{
	w=p[i+3]+p[i+4];
	cout<<w;
    }
	else if(j[k+1]==1&&j[k+3]==1&&a[i]!=j[k]&&a[i+1]!=j[k+2])
	{
	w=p[i]+p[i+1]+p[i+2];
	cout<<w;
}
}
}
	return 0;
	}

