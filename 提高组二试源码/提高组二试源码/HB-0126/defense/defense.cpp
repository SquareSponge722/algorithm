#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int p[100001];
int u[100001];
int v[100001];
int main()
{
    int n,m;
    scanf("%d%d%c",&n,&m);
    for(int i=1;i<=n;++i)
    {
    	scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;++i)
	{
		scanf("%d%d",&u[i],&v[i]);
	}    
}
