//#define DB
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int road[5050][5050]= {0};
int visit[5050]= {0};
int n,m;
bool visitb(int i)
{
    for(int j=1; j<=n; j++)
        if(road[i][j]!=0&&visit[j]==false)
        {
            return false;
        }
    return true;
}
bool slo(int * no,int i)
{
    for(int j=1; j<=n; j++)
    {
        if(road[i][j]!=0&&no[j]==1&&visit[j]==false) return true;
    }
    return false;
}
int main()
{
#ifndef DB
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
#endif
    int str;
    int ta,tb,ti;
    int i,j;
    int bac,now,head;
    int ans[5050],ac=0;
    int node[5050]= {0};
    bool stb=false,_end=false;
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&ta,&tb);
        road[ta][tb]=1;
        road[tb][ta]=1;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            if(road[i][j]!=0)
            {
                str=i;
                stb=true;
                break;
            }
        if(stb==true) break;
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(road[i][j]!=0) node[i]++;
    visit[str]=true;
    now=str;
    ans[++ac]=str;
    for(i=1; i<=n; i++)
    {
        if(road[str][i]!=0)
        {
            now=i;
            ans[++ac]=now;
            visit[i]=true;
            bac=str;
            break;
        }
    }
    //cout<<str<<" "<<visitb(1)<<endl;
//   cout<<"nb:"<<now<<' '<<node[now]<<endl;
    /*   while(1)
       {
           if(())
           {
               now=bac;
               bac=ac>3?ans[ac-3]:str;
                cout<<"tt"<<endl;
           }
           else if(now==str&&node[str]==1) break;
           else
           {
               for(i=1; i<=n; i++)
               {
                   if(road[now][i]!=0&&visit[i]==false)
                   {
                       bac=now;
                       now=i;
                       ans[++ac]=now;
                       visit[i]=true;
                       break;
                   }
                   else if(i==n&&visit[n]==true)  _end=true;
               }
               cout<<"op"<<endl;
               }
               if(_end==true)   break;
              // cout<<now<<endl;
           }
           */
    int bacn=0;
    while(1)
    {
        if(slo(node,now)==true)
        {
            for(i=1; i<=n; i++)
            {
                if(road[now][i]!=0&&node[i]==1)
                {
                    bac=now;
                    now=i;
                    ans[++ac]=now;
                    visit[i]=true;
                    bacn=0;
                    break;
                }
            }
        }
        else if(visitb(bac)==false||visitb(now)==true)
        {
            now=bac;
            bacn++;
            bac=ac>2+bacn?ans[ac-2-bacn]:str;
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                if(road[now][i]!=0&&visit[i]==false)
                {
                    bac=now;
                    now=i;
                    ans[++ac]=now;
                    visit[i]=true;
                    break;
                }
                else if(i==n&&visit[n]==true)  _end=true;
            }
        }
        if(_end==true) break;
         //cout<<now<<endl;
    }
    for(i=1; i<=ac; i++) cout<<ans[i]<<' ';
}
