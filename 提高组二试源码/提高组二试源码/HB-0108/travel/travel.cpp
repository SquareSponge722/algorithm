#include <iostream>
#include <cstdio>
using namespace std;
struct way{int u,v;};
struct city{int k;bool find2;int w[5020];};
city b[5020];
int n,m;
int lu[5020];
bool zou;
int jiance(int x)
{         
int sum=0;
 for(int i=1;i<=b[x].k;i++)
  sum+=b[b[x].w[i]].find2;         
  if(sum==b[x].k-1) return 1;       //若有很多路走返回2 
  if(sum==b[x].k)return 0;           //若只有一条路就返回1
  return 2;                           //若无路走则返回0
}
int daotui(int p)
{
while(!jiance(lu[p]))     //无路则倒退 
p--;
return p;
}



int zhaolu(int x)
{
int i=1;
 {while(b[b[x].w[i]].find2==1) i++;
 int find1=jiance(b[x].w[i]);
 if(find1==0)   {zou=1; b[b[x].w[i]].find2=1;   return b[x].w[i];}                    //没路去别处只能回来                   
 if((find1==2)||(find1==1))   {b[b[x].w[i]].find2=1; zou=0; return b[x].w[i];}   //有路则走小道,zou=0 
}
}


void paixu()
{for(int j=1;j<=n;j++)
   {
      for(int y=1;y<=b[j].k;y++)
         {int p=y;int min=b[j].w[y];
		    for(int i=y;i<=b[j].k;i++)
              if(b[j].w[i]<min){min=b[j].w[i];p=i;}                //将路字典序 
           int h=b[j].w[y];b[j].w[y]=min;b[j].w[p]=h;}
   }
}



int main()
{freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
cin>>n>>m;
way a[n+30];
for(int i=1;i<=m;i++)
 cin>>a[i].u>>a[i].v;              //输入
 
 
 for(int i=1;i<=m;i++)
    {b[a[i].v].k++;
	b[a[i].u].k++;
	b[a[i].u].w[b[a[i].u].k]=a[i].v;
	b[a[i].v].w[b[a[i].v].k]=a[i].u;
	}                           //把路转到city中 

paixu();
int k=3,p=3;
b[1].find2=1;
lu[2]=zhaolu(1);
lu[1]=1;
b[lu[2]].find2=1;
 while(k<=n)
 {k++;lu[k-1]=zhaolu(lu[p-1]);
 //p++;
 if(zou==1) p=daotui(p);       //目的地无路走就倒退 
   p++;      //有路走就走 
 }
 for(int i=1;i<=n;i++)
  {int t=0;
  for(int j=1;j<=n;j++)
   if(lu[j]==i) {t=1;break;}
    if(t==1)continue;
    else lu[n]=i;break;}
for(int i=1;i<=n;i++) if(lu[i]!=0)cout<<lu[i]<<" ";
	// for(int i=1;i<=3;i++)	 cout<<b[35].w[i].s<<" ";    //检测输入的东西 
return 0;
}

