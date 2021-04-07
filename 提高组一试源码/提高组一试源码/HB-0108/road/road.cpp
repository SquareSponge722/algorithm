#include <iostream>
#include <cstdio>
using namespace std;
int day=0;
int a[100008];
void  wa(int q,int p)
{ int w=q;int min=a[q];
 for(int i=q;i<=p;i++)
 if(a[i]<min){w=i;min=a[i];}   //段内最小值 
 for(int i=q;i<=p;i++)
  a[i]=a[i]-min;
  day+=min;
}
int main()
{freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)                      //输入 
 cin>>a[i];
 
wa(1,n); //前几天 
 
 int sum=0;
 for(int i=1;i<=n;i++)
  sum+=a[i];   //判断 
  int s=1;
   int w=n;
  while(sum!=0)
{ int k=0 ;
  for(int i=s-1;i<=n+1;i++)
     {if((a[i]==0)&&(k==2)){k=3;wa(s,i-1);break;}
      if((a[i]>0)&&(k==1)){k=2;}        
	 if((a[i]==0)&&((k==0)||(k==1))){k=1;s=i+1;}
     }
  sum=0;
   for(int j=s;j<=n;j++)
    sum+=a[j];
}
cout<<day;
 
return 0;
}
