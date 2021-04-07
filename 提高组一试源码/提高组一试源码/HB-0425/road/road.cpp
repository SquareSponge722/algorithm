#include<bits/stdc++.h>
using namespace std;
int n;
int d[100001];
inline int read()
{
	int s=0,p=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') p=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*p;
}/*
void violence()
{
	int sum=0;
	int g=0,e;
	while (1)
	{
		int mmin=10001;
		int flag=0;
		int book=0;
		for (int i=1;i<=n;i++)
		{
	     if (d[i]!=0) {flag=1;book=1;}			
		 if (d[i]==0&&book==1) {e=i-1;break;} 	
		 if (d[i]<mmin&&d[i]!=0) mmin=d[i],g=i;
		}
		if (flag==0) break;
		for (int i=1;i<=e;i++)
	    {
	    	d[i]-=mmin;
		    sum+=mmin;
		    cout<<sum<<endl;
		}
	}
	cout<<sum;
}*/
int s[100001];
void work()
{
	long long tot=0;
	d[0]=0;
	for (int i=1;i<=n;i++)
	{
		s[i]=d[i]-d[i-1];
	//	cout<<s[i]<<" ";
	}
	int zzj=1;
	while (1)
	{
//		cout<<zzj<<endl;
		int sum=0,g=100001;
		int flag=0;
		int qi;
		for (int i=zzj;i<=n;i++)
	    {
	    	sum+=s[i];
            if (sum!=0) g=min(sum,g);
	    	if (sum!=0&&flag==0) 
			zzj=i,flag=1,qi=i;
			if(sum==0&&flag==1&&g!=100001)
			{
				s[qi]-=g;
                s[i]+=g;
				tot+=g;
				break;
			}
			if (i==n&&flag==1) 
			{
				s[qi]-=g;
				tot+=g;
			} 
		} 
		//cout<<tot<<endl;
		if (flag==0) break;
	}
	cout<<tot;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
	d[i]=read();
	work();
	return 0;
}
/*
8
1 3 1 3 2 3 1 3
*/
