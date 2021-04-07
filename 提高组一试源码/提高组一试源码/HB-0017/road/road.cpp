/*#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int d[maxn];
int n,m,p,ans=0;
void find(int a,int b)
{
	m=d[a];
    for(int i=a+1;i<=b;i++)
    {
    	if(m>d[i])
    	m=d[i];
	}
	return m;
}
void do(int c,int d)
{
	
	
}
int main()
{
	//freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>d[i];
	for(int i=1;i<=n;i++)
	d[i]=d[i]-m;
	ans=m;
	
	for(int j=1;j<=n;j++)
	for(int k=2;k<=n;k++)
	{
		for(int l=j;l<=k;l++)
		if(d[l]!=0)
		{
			d[l]--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}*/





/*#include<bits/stdc++.h>
using namespace std;
int d[100000],p,q,k,r,n,m,ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	m=d[1];
    for(int i=1;i<=n;i++)
    {
    	if(m>d[i])
    	m=d[i];
    	p=i;
	}
	n=d[1];
	for(int j=1;j<=p;j++)
	{
		if(n<d[j])
		n=d[j];
		q=j;
	}
	k=d[p+1];
	for(int j=p+1;j<=n;j++)
	{
		if(k<d[j])
		k=d[j];
		r=j;
	}
	ans=k+n;
	cout<<ans;
	return 0;
}*/



#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int d[maxn],k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	sort(d+1,d+n+1);
	if(d[n]+d[n-1]==2*d[n])
	ans=d[n]+d[n-1]-1;
	else
	ans=d[n]+d[n-1];
	cout<<ans;
}
	



















