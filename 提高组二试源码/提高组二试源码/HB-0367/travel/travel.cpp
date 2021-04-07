#include<iostream>
#include<cstdio>
using namespace std;
int ans,n,m;
int f[3000][3000];
int fa[1000];
int a[1000];
int c,b;
int book[1000];
void findd(int g,int j,int z)
{
    if(ans>=n)return;
    int bb=0,b=0;
    f[g][j]++;
    f[j][g]++;
    for(int h=1;h<=n;h++)
    {
    	for(int p=1;p<=ans;p++)
    	{
    		if(f[a[p]][h]==z)
    		{
    			fa[h]=a[p];
    			if(book[j]==0)
            {ans++;
            a[ans]=j;book[j]=1;}
    			findd(a[p],h,z);
			}
		}
        if(f[h][j]==z&&b==0)
        {
            bb=1;
            fa[h]=j;
            if(book[j]==0)
            {ans++;
            a[ans]=j;book[j]=1;}
            findd(fa[h],h,z);
        }
    }
    if(bb==0)
    {
    	if(f[g][j]<=z+1&&book[j]==0)
    	{ans++;
    	a[ans]=j;book[j]=1;}
        findd(fa[g],g,z);
    }
    return ;
}
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ans++;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>c>>b;
        f[c][b]=1;
        f[b][c]=1;
    }
    a[1]=1;
    for(int i=1;i<=n;i++)
    {
        if(f[1][i]==1)
        {
        	fa[i]=1;
            findd(1,i,1);
    }}
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    /*cout<<endl;
    cout<<endl;
    for(int i=1;i<=n;i++)
    	{for(int j=1;j<=n;j++)
    	cout<<f[i][j]<<" ";
    	cout<<endl;}*/
    return 0;
}
