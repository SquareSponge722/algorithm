#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int t,n;
int a[10000],b[10000];
bool pd(int a,int b);//pd为判断是否互质的函数，若为1则互质
int main()
{
	freopen("money1.in","r",stdin);freopen("out.txt","w",stdout);
	cin>>t;
	while(t--)
	{
		int maxn=0;int k=0;int ans;int k1=1;
		int n2=1; 
        cin>>n;		
        for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]==1) {cout<<"1"<<endl;continue;}
		b[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n2;j++)
			if(!pd(a[i],b[j])) {k1=0;break;}
			if(k1) b[++n2]=a[i];
			k1=1;
		}
		for(int i=1;i<=n;i++) 
	    {
			for(int j=i+1;j<=n;j++)
		    {if(pd(a[i],a[j])) {maxn=a[i]*a[j]-a[i]-a[j];k=1;break;}}
		    if(k) break;
        }
		for(int i=2;i<=n;i++) if(b[i]>maxn) ans=i-1;
		cout<<n2<<endl;
	}
	return 0;
}
bool pd(int a,int b)
{
	for(int i=2;i<=sqrt(min(a,b));i++) if(a%i==0&&b%i==0) return 0;
	if(a%b==0||b%a==0) return 0;
	return 1;
}
