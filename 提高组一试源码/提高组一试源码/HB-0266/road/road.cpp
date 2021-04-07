#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
int ans=0x7ffffff,a[100100],n;
bool vis[100100];
bool depth(int l,int r)
{
	bool sum;
	for(int i=l;i<=r;i++)
	if(a[i]!=0) sum=0;
	if(!sum) return false;
	else return true;
}
void dealt(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
	 if(a[i]<=0) break;
	 else a[i]-=1;
	}
	
}
void dfs(int l,int r,int sum)
{
	if(depth(l,r)) {ans=min(ans,sum); return;}
     for(int i=1;i<=n;i++)
     {
     	for(int j=i;j<=n;j++)
     	{   		
         dealt(i,j);
         dfs(i,j,sum+1);
     }
	 }
}

int main()
{
//	freopen("road.in","r",stdin);
//	freoepn("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dfs(1,1,0);
    cout<<ans;
	return 0;
}

