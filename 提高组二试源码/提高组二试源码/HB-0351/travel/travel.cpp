#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100000

using namespace std;
int a[MAXN],b[MAXN],h,f[MAXN],d[MAXN],m,n,p;
int bb[MAXN];
bool b1[MAXN];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>f[i];
		a[i+m]=f[i];
		f[i+m]=a[i];
	}
		for(int j=2;j<=m;j++)//记录每一个城市 
		{
			h=MAXN;
			b[1]=1;//从每一个城市开始
			bb[1]=1;
			b1[1]=1;
			p=0;
			for(int k=1;k<=2*m;k++)//找爸爸 
			{ 
				if(a[k]==b[j] && bb[a[k]]!=2 && b1[f[k]]==0)
				{
					h=min(h,f[k]);
					p=k;
				}
				if(a[k]==b[j-1] && bb[a[k]]!=2 && b1[f[k]]==0)
				{
					h=min(h,f[k]);
					p=k;
				}
			}
			b[j]=h;
			b1[f[p]]=1;
			bb[a[p]]++;
		}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
