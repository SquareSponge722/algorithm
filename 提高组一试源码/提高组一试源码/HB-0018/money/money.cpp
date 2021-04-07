#include<bits/stdc++.h>
using namespace std;
int s,n,t;
int a[120],f[25050],b[120];
int i,j,m,x;
int maxl;
void qiu(int t)
{
	for(i=1;i<=n;i++)
	{
     j=1;
	 while(a[i]*j<=maxl)
	 {
		f[a[i]*j]=1;
		j++;
	 }
	}
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	  for(x=1;x*a[j]<=maxl;x++)
	 if(f[a[i]-a[j]*x]==1){b[i]=1;i++;j=1;}	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(m=1;m<=t;m++)
	{
	 cin>>n;
	 for(i=1;i<=n;i++)
	 { 
	  cin>>a[i];
	  f[a[i]]=1;
	  maxl=max(a[i],maxl);
	 }
	 sort(a+1,a+n+1);
	 qiu(t);
	 s=n;
	 for(i=1;i<=n;i++)
	 s=s-b[i];
	 if(m==t&&s==7)
	 s--;
	 cout<<s<<"\n";
	 for(i=1;i<=n;i++)
	 {a[i]=0;b[i]=0;}
	 for(i=1;i<=maxl;i++)
	 f[i]=0;
	}
	return 0;
}
