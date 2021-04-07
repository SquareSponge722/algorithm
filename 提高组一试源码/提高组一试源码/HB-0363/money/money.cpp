#include<cstdio>
#include<iostream>
using namespace std;
int a[101],f[101],c[101];
/*void qsort(int r,int l,int a[])
{
	int i=r,j=l,temp,mid=a[(r+l)/2];
	do{
		while(a[i]<mid)i++;
		while(a[j]>mid)j--;
		if(i<=j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<=j);
	if(i<l)qsort(i,l,a);
	if(j>r)qsort(r,j,a);
}*/

int fun(int x,int c[],int num)
{
	
	if(x==0) return 0;
	if(num==0) return 1;
	return fun(x-c[num],c,num);
	return fun(x-c[num],c,num-1);
	return fun(x,c,num-1);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,num,n,sum,i,ans=0,j,k;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		for(j=1;j<=101;j++){
			a[i]=0;c[i]=0;f[i]=0;
		}
		scanf("%d",&n);
		for(j=1;j<=n;j++){
				scanf("%d",&a[j]);
			}
		if(n==1){
			printf("1\n");
			return 0;
		}
		if(n==2){
			if(a[2]%a[1]==0||a[1]%a[2]==0)printf("1\n");
			else printf("2");
			return 0;
		}
		else {
			//qsort(1,n,a);
			for(j=1;j<=n;j++)
				for(k=j+1;k<=n;k++)
					if(a[j]>a[k])swap(a[j],a[k]);
			f[1]=1;c[1]=a[1];num=1;k=2;
			for(j=2;j<=n;j++){
				f[i]=fun(a[i],c,num);
				if(f[i]){
					num++;
					c[k]=a[j];
					k++;
				}
			}
		printf("%d",num);
		
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

