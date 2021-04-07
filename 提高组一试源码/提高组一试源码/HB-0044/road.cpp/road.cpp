#include<iostream>
#include<cstdio>
using namespace std;
int day=0;
int ans=99999999;

int a[n],n=0;
void slove(int n,int day,int k,int u,int j)
  {  if(day<ans)
     ans=day;
	      for(int i=0,int i<=n,i++)
     { if ((a[i]==0)&&(i==0))
        {for(int k=i,int k<=n,k++)
         a[k]-1;
         int day+1;
          }
       if ((a[i]==0)&&(i>0))
        {for(int j=i-1,int j<=n,j++)
          {a[j]-1;}
          int day+1;
         for(int u=i+1,int u<=n,u++)
          {a[u]-1;}
          int day+1;
         }
       else 
        {a[i]-1;}
        int day+1;
        return;
      }
freopen("road.in","r",stdin);
freopen("road.out","rw",stdout);
int main(int n,int day,int ans);
  { int n=0;
	  {cin>>n;}
   for(int i=0,int i<n,i++)
   {cin>>a[n];}
   slove(int i,int day);
   for(int i=0,int i<n,i++)
   {cout<<ans; 
   return 0;
    }
  }