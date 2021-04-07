#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001],c[5001],d[5001];
/*void find(int a,int b)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1||b[i]==1)
		p=i;
	}
	
}*/


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,p,k=1;
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<m;i++)
	scanf("%d %d\n",&a[i],&b[i]);
	c[1]=1;
	for(int i=1;i<=m;i++)
	{
		if(a[i]==k)
		k++;
		c[i]=i;
	}
	for(int i=1;i<=n;i++)
	cout<<c[i]<<" ";
	return 0;
}





/*#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0;
}*/


/*#include<bits/stdc++.h>
using namespace std;
int a[5001][5001];
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,m;
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u][v]=1,a[v][u]=1;
	}
	for(int i=1;i<=n;i++)
    cout<<a[i][1]<<" ";
    return 0;
}*/


















