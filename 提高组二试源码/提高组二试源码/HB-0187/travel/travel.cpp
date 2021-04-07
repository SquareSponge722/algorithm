#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t=1,minn,flag,temp,rec;
int n,m;
int a[10005],ans[10005],b[10005];

void work(int k)
{
	for(int i=1; i<=2*m; i++)
	{
		if(a[i]==k&&b[(i+1)/2]==0)
		{
			if(i%2==0)
			{
				if(a[i-1]<minn)
				{
					minn=a[i-1];
					flag=i;
				}

			}
			else
			{
				if(a[i+1]<minn)
				{
					minn=a[i+1];
					flag=i;
				}
			}
			temp=1;
		}
   	}
}

void mysearch(int k)
{
	if(t>n)return;
	ans[t]=k;
	temp=0;
	minn=9999;
	work(k);
	if(temp==0)return;
	b[(flag+1)/2]=1;
	k=minn;
	t++;
	mysearch(k);
}


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=2*m; i++)cin>>a[i];
    mysearch(1);
    memset(b,0,sizeof(b));
    sort(a+1,a+2*m+1);
	for(int i=1; i<=2*m; i++)
	{
	    if(ans[i])
		{
			cout<<ans[i]<<' ';
			b[ans[i]]=1;
		}
		else
		{
			for(int j=1; j<=2*m; j++)
			if(!b[a[j]])
			{
				cout<<a[j]<<' ';
			    b[a[j]]=1;
			}
		} 	/**/
	}
	//for(int i=1; i<=2*m; i++)cout<<b[i];
	return 0;
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
1 3 2 5 4 6
*/
