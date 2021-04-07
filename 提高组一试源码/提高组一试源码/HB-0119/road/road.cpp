#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<functional>
#include<time.h>
#include<stdio.h>
using namespace std;
int main()
	{
		freopen("road.in","r",stdin);
		freopen("road.out","rw",stdout);
	int a,c;
 	int count=0;
 	int v = 0;
 	int b =0;
 	int t=0;
 	int x=0;
 	int y=0;
 	cin>>a;
	 int d[a],f[10000],r[100000];
 	for(int i=0;i<a;i++)
		{
 		cin>>d[i];
		}
			  while(v==0)
			  {
			   for(int i=0;i<a;i++)
		 	{
		 	if(d[i]==0)
			 {
			   v++;
			 f[t]=i;t++;
		}
			  }
			  if(v==0)
			  {
			  count++;
			  for( int q=0;q<a;q++)
		 	 	 {
		 	 	 	d[q]=d[q]-1;
				   }
				   }
				    
				   } 
				   v=1;
				   
				   	for(int i=0;i<a;i++)
		 	{
				   	if(d[i]!=0)
				 {
				 	x=0;
				 	r[x]=i;
			   		x++;
			   		v=1;
				}
			
				{
		  			v=0;
				}
				
			}
			for(int h=0;h<a;h++)
		 	{
		 	if(d[h]==0)
			 {
			 	t=0;
			 f[t]=h;t++;
		}
	}
	for(int l=0;l<a;l++)
	{
		if(f[l]>r[1])
		{
			d[r[l]]=d[r[l]]-1;
			count++;
		}
	}

				 
				   
		cout<<count*3<<endl;
		
}
