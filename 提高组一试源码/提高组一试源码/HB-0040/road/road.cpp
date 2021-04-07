#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int d[1000000];
int main()
{
 int n,t=0,i=0;
 scanf("%d\n",&n);
 t=t+n+2;
 while((scanf("%d",&d[i]))==1) 
   {
    while(d[i]!=0) 
	  {
	  --d[i];
      } 
	++t; 
   }
  printf("%d",t);
  return 0; 
}
