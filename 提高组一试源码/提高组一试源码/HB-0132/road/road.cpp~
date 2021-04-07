#include<iostream>
#include<cstdio>



using namespace std;
int a[10000]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=0,d=0;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 {
		 scanf("%d",&a[i]);
		}
	
	
	int max,ma=0,o=1,reg=0;
	while(1)
	{reg=0;
		ma=0;
	 max=1000000;
	for(int i=1;i<=n;i++)
	 {
     	if(a[i]<max&&a[i]!=0)
		 {max=a[i];
			ma=i;
		 }
	 }
	
	 int l=0,r=0;
	 if(max!=1000000)
	 d=d+a[ma];
	
	 for(int i=ma;i>=1;i--)
	 {
		 if(a[i]==0){l=i+1;break;}
	 }
	 for(int i=ma;i<=n;i++)
		 if(a[i]==0){r=i-1;break;}
	if(l!=0&&r!=0)for(int i=l;i<=r;i++)a[i]=a[i]-a[ma];
	if(l==0&&r==0)for(int i=1;i<=n;i++)a[i]=a[i]-a[ma];
	 if(l==0&&r!=0)for(int i=1;i<=r;i++)a[i]=a[i]-a[ma];
	 if(l!=0&&r==0)for(int i=l;i<=n;i++)a[i]=a[i]-a[ma];	
	for(int i=1;i<=n;i++)if(a[i]>0){reg=1;break;}
	
	if(reg==0){break;}
	
   }
   
   printf("%d",d);
  
   
   return 0;
}
