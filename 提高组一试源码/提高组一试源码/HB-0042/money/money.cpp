#include<bits/stdc++.h>
using namespace std;
int m,n,flag,a[100000],f[10000][10000],pan[100000],b[100000];
void fns(int ia[],int lf[10000][10000],int u)
{
	int f1,f2,f3;
	for(int o=1;o<=u;o++)
    	{
    	  lf[o][ia[o]]=1;
    	  for(int j=1;j<=1100;j++)
    	  {
    	  	if(j==ia[o])
    	  	continue;
    	  	f1=lf[o][j-ia[o]];
    	  	f2=lf[o-1][j-ia[o]];
    	  	f3=lf[o-1][j];
    	  	lf[o][j]=f1||f2||f3;
		  }
	    }
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    int t1,t2,t3;
    int mm;
    cin>>n;
    for(int k=1;k<=n;k++)
    {
    	cin>>m;
    	memset(a,0,sizeof(0));
    	memset(f,0,sizeof(0));
    	for(int i=1;i<=m;i++)
    	cin>>a[i];
    	f[0][0]=1;
    	sort(a+1,a+m+1);
    	flag=0;
    	if(a[1]==1)
    	{
    		cout<<"1";
    		continue;
		}
    	for(int l=2;l<=m;l++)
    	{
    		if(a[l]>a[1]&&a[l]%a[1]!=0)
    		{
    			mm=a[l];
    			flag=1;
				break; 
			}
		}
		if(flag==0)
		{
			cout<<"1"<<endl;
			continue;
		}
		flag=0;
		  for(int k=1;k<=m;k++)
		  for(int p=1;p<=m;p++)
		  {
		  	if(a[k]!=a[p]&&a[k]%a[p]==0)
		  	flag=1;
		  }
		 if(flag==0&&m>=5)
		 {
		 	cout<<m<<endl;
			continue;
		 } 
    	for(int o=1;o<=m;o++)
    	{
    	  f[o][a[o]]=1;
    	  for(int j=1;j<=1100;j++)
    	  {
    	  	if(j==a[o])
    	  	continue;
    	  	t1=f[o][j-a[o]];
    	  	t2=f[o-1][j-a[o]];
    	  	t3=f[o-1][j];
    	  	f[o][j]=t1||t2||t3;
    	  	pan[j]=f[o][j];
		  }
	    }
	    b[1]=a[1];
	    int p=2;
	    int uu=0;
	    for(int k=1;k<=mm;k++)
	    {
	    	fns(b,f,p);
	    	for(int ll=1;ll<=1100;ll++)
	    	if(pan[ll]=!f[p][ll])
	    	{
	        b[p]++;
	    	if(b[2]>mm)
	    	{
	    		p++;
	    		b[p]=a[p];
			}
			uu=1;
			}
			if(k!=m&&uu==0)
	    	{
			cout<<m<<endl;
			break;
	        }
	        if(k==m&&uu==0)
	        {
	        cout<<m;
	        break;
	        }
	        uu=0;
	   }
/*		 for(int o=1;o<=m;o++)
		 {
    	  for(int j=1;j<=35;j++)
    	  {
    	    cout<<f[o][j]<<" ";
		  }
		  cout<<endl;
	     }
*/
	}
    return 0;
}

