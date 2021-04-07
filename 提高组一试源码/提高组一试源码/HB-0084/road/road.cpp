#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define rg register
using namespace std;
vector<int>h[10010];
int a[100010]={0};
bool out[100010]={false};
inline int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,maxx=0,sum=0;
    cin>>n;
    maxx=0;
	for(rg int i=1;i<=n;i++)
	{
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	for(rg int i=0;i<=maxx;i++)
	{
		h[i].push_back(0);
	}
	for(rg int i=1;i<=n;i++)
	{
		h[a[i]][0]++;
		h[a[i]].push_back(i);
	}
	int f=1;
	for(rg int i=1;i<=n;i++)
	{
		if(a[i]==0&&a[i-1]!=0&&a[i-1]!=0)
		{
			f++;
			out[i]=true;
		}
		if(a[i]==0)
		{
			out[i]=true;
		}
	}
	if(a[n]==0&&n!=1)
	{
		f--;
	}
	if(a[n]==0&&n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	out[0]=true,out[n+1]=true;
	for(rg int i=1;i<=maxx;i++)
	{
		sum=sum+f;
	    for(rg int j=1;j<=h[i][0];j++)
		{
			if(out[h[i][j]]!=true&&out[h[i][j]+1]!=true&&out[h[i][j]-1]!=true)
			{
				f++;
			}
			else if(out[h[i][j]-1]==true&&out[h[i][j]+1]==true)
			{
				f--;
			}
			out[h[i][j]]=true;
		}
	}
	cout<<sum<<endl;
	return 0;
}
//Fei2Xue@Lian$Tian!
/*
6
4 3 2 5 3 5
*/
/*
15
1 2 0 0 1 2 0 0 0 0 0 0 0 0 1
*/



