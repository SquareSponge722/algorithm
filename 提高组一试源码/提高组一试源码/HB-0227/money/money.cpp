#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#define N 100000+100
using namespace std;
int n,ans[N],flag[N],minv=N;
int a[N],m,t,tt,kk,ttt;
int dp()
{
	tt=0;
	memset(ans,0,sizeof(ans));ans[0]=1;
	for(int l=0;l<=1000;l++)
	{
		for(int k=1;k<=m;k++)
		{
			if(flag[k]==1)
			{
				if(ans[l]==1)ans[l+a[k]]=1;
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		if(ans[a[k]]==0){tt=1;}
	}
    if(tt==0){kk=1;cout<<ttt<<endl;return 0;}
	//for(int i=1;i<=m;i++)if(flag[i]==1)cout<<a[i]<<" ";
	//cout<<endl;
}
int qp(int x,int num)
{
	if(kk==1)return 0;
    if(x>m+1){return 0;}
	if(num<0)return 0;
	if(num==0){dp();return 0;};
	flag[x]=1;
	qp(x+1,num-1);
	flag[x]=0;
	qp(x+1,num);
}

int main()
 {
 	freopen("money.in","r",stdin);
 	freopen("money.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		memset(flag,0,sizeof(flag));
 		memset(ans,0,sizeof(ans));
 		ans[0]=1;kk=0;
 		cin>>m;
 		for(int j=1;j<=m;j++)
 		{
		  cin>>a[j];
		}
		for(int j=1;j<m;j++)
		{ 
		    tt=0;
			memset(flag,0,sizeof(flag));
		    memset(ans,0,sizeof(ans));
		    ans[0]=1;
			t=j;ttt=j;
			qp(1,t);
			/*for(int k=1;k<=m;k++)
			{
			   if(ans[a[k]]==0){tt=1;break;}
			}
			if(tt==0){kk=1;cout<<j<<endl;break;}*/
	    }
	    if(kk==0)cout<<m<<endl;
	 }
 	return 0;
}