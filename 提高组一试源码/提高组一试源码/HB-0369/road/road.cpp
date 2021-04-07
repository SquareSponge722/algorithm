#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<iomanip>
#include<cstdlib>
using namespace std;
int maxx=0;
int total;
int repeat;
long long minn=999999999;
long long ans=0;
long long orgdep[999999];
long long tmp[999999];
int checkk;
int minnnn=9999999;
bool bbb=true;
int ttt=0;
int total1=total;
bool mycheck()
{
    ttt=0;
    for(int i=1;i<=total;i++)
    {
        if(tmp[i]==0)
        {
            ttt++;
        }
        if (tmp[i]!=0)
        {
            /*if(ttt==99995)
            {cout<<tmp[100000]<<'!';}*/
            ///cout<<ttt<<endl;
            if(ttt==checkk)
            {
                bbb=false;
            }
            checkk=ttt;
            return 0;
        }
    }
    return 1;
}
void dosth()
{
    long long minnn;
    for(int k=1;k<=total;k++)
   {
       long long myloc;
       bool b;
       if(tmp[k]!=0&&tmp[k-1]==0)
       {
           myloc=k;
           minnn=tmp[k];
       }
       if(tmp[k]!=0&&tmp[k]<=minnn)
       {
           minnn=tmp[k];
       }
       if(tmp[k]==0&&k!=total&&myloc!=999999999)
       {
           for(int j=myloc;j<=(k-1);j++)
           {
               ///cout<<minnn<<" _______________"<<endl;
               tmp[j]-=minnn;
           }
           ans+=minnn;
           myloc=999999999;
       }
       if(k==total&&tmp[k]!=0)
       {
           while(total1!=myloc)
           {
           for(int i=myloc;i<=total1;i++)
           {
               if(tmp[i]<=minnnn&&tmp[i]!=0)
               {
                   minnnn=tmp[i];
               }
           }
            for(int j=myloc;j<=total1;j++)
           {
               tmp[j]-=minnnn;
           }
           ans+=minnn;
           while(tmp[total1]==0)
           {
               total1--;
           }}
          /// cout<<endl;
       }
   }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   cin>>total;
   for(int x=1;x<=total;x++)
   {
       cin>>orgdep[x];
       tmp[x]=orgdep[x];
       if(tmp[x]<minn)
       {
           minn=tmp[x];
       }
       if(tmp[x]>maxx)
       {
           maxx=tmp[x];
       }
   }

   for(int y=1;y<=total;y++)
   {
       tmp[y]-=minn;
   }
   ans+=minn;
   while(!mycheck())
   {
       dosth();
      /*for(int i=1;i<=total;i++)
       {
           cout<<tmp[i]<<' ';
       }
       cout<<endl;*/
      /// cout<<ans<<"----"<<endl;
      if(ttt==0)
      {
          break;
      }
   }
   cout<<ans;
   return 0;
}
