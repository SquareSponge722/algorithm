# include<cstdio>
# include<cstring>
# include<iostream>
# include<algorithm>
# include<cmath>
# include<stack>
# define N 100005
using namespace std;
int n;
int a[N];
int pos[N][21];
int minn[N][21];
int tot;
bool flag[N];
int rmq(int l,int r)
{
	int ans=0;
	int k=log2(r-l+1);
	ans=min(minn[l][k],minn[r-(1<<k)+1][k]);
	return ans;
}
int ask(int l,int r)
{
	int k=log2(r-l+1);
	if(minn[l][k]>minn[r-(1<<k)+1][k])
		return pos[r-(1<<k)+1][k];
	else
		return pos[l][k];
}
void dele(int l,int r,int stand)
{
	if(l==r) 
	{
		tot+=a[l]-stand;
	}
	else
	{
		int start=rmq(l,r);
		tot+=start-stand;
		stand=start;
		int po=ask(l,r);
		if(l<=po-1)
			dele(l,po-1,stand);
		if(r>=po+1)
			dele(po+1,r,stand);
	}
	return ;
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		minn[i][0]=a[i];
		pos[i][0]=i;
	}
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
		  if(minn[i][j-1]>minn[i+(1<<(j-1))][j-1])
			{
				minn[i][j]=minn[i+(1<<(j-1))][j-1];
				pos[i][j]=pos[i+(1<<(j-1))][j-1];
			}
		  else 
		  	{
		  		minn[i][j]=minn[i][j-1];
		  		pos[i][j]=pos[i][j-1];
			}
		}		
	dele(1,n,0);
	printf("%d",tot);
	return 0;
}
