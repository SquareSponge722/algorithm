#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[100],m[20];
int f1,f2;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	
	for(int i=0;i<T;i++)
	{
		cin>>n;
		m[i]=n;
		for(int j=0;j<n;j++)
		    cin>>a[j];
		sort(a,a+n);
		f1=a[0];
		for(int j=1;j<n;j++)
		{
			if(f2==0)
			{
				if(a[j]%f1!=0)
				{
					f2=a[j];
					goto A;
				}
				else
			    {
				    m[i]--;
				    a[j]=-1;
				    goto A;
			    }
			}
			//////////////////////////////////////////
			if(a[j]>=f1*f2-f1-f2)
			{
				m[i]--;
				a[j]=-1;
				goto A;
			}
			else
			{
				bool ok=0;
				for(int k=0;k<=a[j]/f2;k++)
				    if((a[j]-k*f2)%f1==0) ok=1;
				if(ok==1) m[i]--;
			}
			A:;
		}
	}
	for(int i=0;i<T;i++)
	    cout<<m[i]<<endl;
	return 0;
}

