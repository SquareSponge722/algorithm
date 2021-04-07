#include<bits/stdc++.h>
using namespace std;
const int mn=110;
int f1[mn],f2[mn];
int a[mn],aa[mn],b[mn];
int n,maxn,t,ans;
bool t1,t2;
string s1,s2,s3;
void dfs(int i,int p)
{
	if(i>p)
	{
		for(int i=1;i<=mn;i++)
			f2[i]=0;
		f2[0]=1;
		for(int i=1; i<=p; i++)
			for(int j=aa[i]; j<=maxn; j++)
			{
				t1=f2[j];
				t2=f2[j-aa[i]];
				f2[j]=t1||t2;
			}
		s2="";
		for(int j=1; j<=maxn; j++)
			s2+=f2[j]+'0';
		if(s2==s1) ans=min(ans,p);
		return;
	}
	for(int k=1;k<=n;k++)
		if(!b[k])
		{
			aa[i]=a[k];
			b[k]=1;
			dfs(i+1,p);
			b[k]=0;
		}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=mn;i++)
			f1[i]=0;
		ans=99999;
		maxn=0;
		s1=s2="";
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
			if(a[i]>maxn) maxn=a[i];
		}
		if(n==1) 
		{
			cout<<1<<endl;
			continue;
		}
		f1[0]=1;
		for(int i=1; i<=n; i++)
			for(int j=a[i]; j<=maxn; j++)
			{
				t1=f1[j];
				t2=f1[j-a[i]];
				f1[j]=t1||t2;
			}
		for(int j=1; j<=maxn; j++)
			s1+=f1[j]+'0';
		for(int p=2;p<=n;p++)
			dfs(1,p);
		cout<<ans<<endl;
	}
	return 0;
}

