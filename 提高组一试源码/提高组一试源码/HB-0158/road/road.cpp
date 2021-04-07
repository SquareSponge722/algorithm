#include<cstdio>
using namespace std;
int d[100005];
int main()
{
FILE *fin,*fout;
fin=fopen("road.in","rb");
fout=fopen("road.out","wb");
int n,s=0,limit;
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
     fscanf(fin,"%d",&d[i]);
for(int i=0;i<n;i++)
   if(d[i]!=0)
     {limit=d[i];
	  for(int j=0;j<limit;j++)
         for(int x=i;x<=n;x++)
            {
		    if(d[x])
            d[x]=d[x]-1;
            else
               {
		  	 s++;
               break;
		       }
	        }
      }  
fprintf(fout,"%d",s);
return 0;
}
