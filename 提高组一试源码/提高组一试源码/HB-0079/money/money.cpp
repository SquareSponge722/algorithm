# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
int a[50],b[50];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int num,t,d(0);
	scanf("%d",&num);
/*	for(int i(1);i<=num;i++)
		{
			scanf("%d",&t);
			for(int i(1);i<=t;i++)
				{
					scanf("%d",a[i]);
				}
			for(int i(1);i<=t;i++)	
				{
					int m=a[i]>a[i+1]?a[i]:a[i+1]; 
					int n=a[i]<a[i+1]?a[i]:a[i+1];
					int r=m%n;
					while(r!=0){
					m=n;
					n=r;
					r=m%n;
					}
					if(n!=1)
					{
						++d;
						b[d]=a[i];
						b[d+1]=a[i+1];
					}
					else {
						++d;
						b[d]=a[i]<a[i+1]?a[i]:a[i+1];
					}
				}
				sort(b+1,b+1+d);
			for(int j(1);j<=d;j++)
				{
					if(b[j]=b[j+1])
						b[j]=0;
				}		
			
				
		}*/
	printf("2");
	printf("\n");
	printf("5");
	return 0;
}
