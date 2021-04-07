#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[21][101];
int ans[21];
long int n[21];
int c[21][5001];
int cp[21];

int ys(int x,int y)
{
	 int z;
     while(!((x%y)==0))
     {
     	z=x;
     	x=y;
     	y=z%y;	
	 }
	 return y;
}


int shu(int v)
{
	int g;
	g=((1+(v-1))*(v-1))/2;
	return g;
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=t;++i)
	{
		
	    cp[i]=shu(n[i]);
	}
	for(int j=1;j<=t;++j)
	{
		for(int i=n[j];i>=1;--i)
		{
			for(int k=i-1,q=1;k>=1;--k)                
			{
				c[j][q]=ys(a[j][i],a[j][k]);
				++q;
			}
		}
	}
	for(int i=1;i<=t;++i)
	{
		ans[i]=cp[i];
	}
	for(int i=1;i<=t;++i)
	{
		for(int j=1;j<=cp[i];++j)
		{
			if(!((c[i][j])==1))
			{
				--ans[i];
			}
		}
	}
	for(int i=1;i<=t;++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
