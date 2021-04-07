#include<bits/stdc++.h>
using namespace std;
int n;
int a[101];
int T;
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
}
int b[25001];
void pianfen2()
{
	if (a[1]%a[2]==0||a[2]%a[1]==0) cout<<1<<endl;
	else cout<<2<<endl;	
}
void pianfen3()
{
	int sum=3;
	sort(a+1,a+4);
	int z=a[1],y=a[2],x=a[3];
	//cout<<z<<y<<z;
	if (x%z==0) 
	{
		sum--;
	}
	if (y%z==0) sum--;
	if (sum==3)
	{
		int k=1;
		int flag=1;
		while (x>=y*k)
		{
		 if ((x-y*k)%z==0) 
		 {
		 sum--;
		 flag=0;
         break;
		 }
		 k++;
		}
		if (flag)
		{
			k=1;
			while (x>=z*k)
			{
			  if ((x-z*k)%y==0)
			  {
			    sum--;
				break; 	
			  }
			  k++;
			}
	    }
	}
	cout<<sum<<endl;
}

void pianfen4()
{
	sort(a+1,a+5);
	int x=a[4],y=a[3],z=a[2],w=a[1];
//	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
	if (x%y==0||x%z==0||x%w==0||y%z==0||y%w==0||z%w==0)
	{
		if(x%y==0||x%z==0||x%w==0){pianfen3();}
		else if (y%z==0){a[3]=x;pianfen3();}
		else if (y%w==0){a[3]=x;pianfen3();}
	    else if (z%w==0){a[2]=x;pianfen3();}
	} 
	else
	{
 		int flag=1;
 		//cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
		 for (int i=0;flag&&y*i<=x;i++)
         for (int j=0;j*z+y*i<=x&&flag;j++)
		  for (int e=0;e*w+j*z+y*i<=x&&flag;e++)
		{
			//cout<<"hi";
		
			if (i!=0||j!=0||e!=0)
			if (x%(i*y+j*z+e*w)==0)
			{
				flag=0;
//				cout<<"zzj";
				pianfen3();
				break;
			}
	 }
//		cout<<endl<<flag<<endl;
		if (flag)
		{
			for (int i=0;flag&&z*i<=y;i++)
			for (int j=0;w*j<=y&&flag;j++)
			{
				int s=z*i+w*j;
				if (s!=0&&y%s==0)
				{
					flag=0;
					a[3]=x;
					pianfen3();
					break;
				}
			}
	    }
//	    cout<<flag;
		if (flag) cout<<4<<endl;       
    }
}

void pianfen5()
{
	sort(a+1,a+6);
	int x=a[5],y=a[4],z=a[3],w=a[2],q=a[1];
	int flag=1;
	for (int i=0;flag&&y*i<=x;i++)
      for (int j=0;j*z+y*i<=x&&flag;j++)
		for (int e=0;e*w+j*z+y*i<=x&&flag;e++)	
         for (int t=0;flag&&e*w+j*z+y*i+t*q<=x;t++)
    {
    	int s=e*w+j*z+y*i+t*q;
	    if (s!=0)
	    {
	    	if (x%s==0) 
	    	{
	    		flag=0;pianfen4();break;
			}
		}
	}
	if (flag)
	{
      for (int j=0;j*z<=x&&flag;j++)
		for (int e=0;e*w+j*z<=x&&flag;e++)	
         for (int t=0;flag&&e*w+j*z+t*q<=x;t++)
		{
    	int s=e*w+j*z+t*q;
	    if (s!=0)
	    {
	    	if (y%s==0) 
	    	{
	    		flag=0;a[4]=x;pianfen4();break;
			}
		}
		}		
	}
	if (flag)
	{
		for (int e=0;e*w<=x&&flag;e++)	
         for (int t=0;flag&&e*w+t*q<=x;t++)
		{
    	int s=e*w+t*q;
	    if (s!=0)
	    {
	    	if (z%s==0) 
	    	{
	    		flag=0;a[3]=x;pianfen4();break;
			}
		}
		}			
	}
	if (flag)
	{
       if (w%q==0)
	   {
	   	 a[2]=x;flag=0;pianfen4();
	   }	
	}
	if (flag) cout<<5<<endl;	
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);	
	T=read();
	for (int zzj=1;zzj<=T;zzj++)
	{
		n=read();
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
		a[i]=read();
		if (n==1)
		{
			cout<<1<<endl;continue;
		}
		else if (n==2)
		{
            pianfen2();
			continue;
		}
		else if (n==3)
		{
			pianfen3();
			continue;
		}
		else if (n==4)
		{
			pianfen4();
			continue;
		}
		else if (n==5)
		{
			pianfen5();
			continue;
		}
		else
		{
			sort(a+1,a+n+1);
			if (a[1]==1) cout<<1<<endl;
			else
			{
				int tot=1;
				for (int i=2;i<=n;i++)
				{
					if (a[i]!=a[i-1]) tot++;
				}
				cout<<tot<<endl;
			}
		}
	}
	return 0;
}
/*
1 
4
13 11 17 19
*/
