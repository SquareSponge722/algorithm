#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
void qsort(int ,int);
int a[25001],a1[24001];
int ok=0;
bool pd(int b,int a){
	if(b%a==0) return 1;
	else return 0;
}
int n,m,i,j,k,_max,x;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;  cin>>t;
	while(t>0){
		t--;
	
	cin>>n;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	i--;
	qsort(1,i);
	//_max=a[i];
	if(i==2){
		if(pd(a[2],a[1])) 
		  cout<<1<<endl;
		else cout<<2<<endl;
		continue;
	}	
	if(i==3){
		if(pd(a[2],a[1])&&pd(a[3],a[1]))  {cout<<1<<endl; continue;}
		else if(pd(a[2],a[1])||pd(a[3],a[1])||pd(a[3],a[2])) {cout<<2<<endl; continue;}
		else{
		    int h=a[3];
			while(h>0){
			h-=a[1];
			if(pd(h,a[2])) {cout<<2<<endl;  ok=0;  break; }
			else ok=1;
			}
		}
		if(ok) cout<<3<<endl;
		}

	}
		
	fclose(stdin);  fclose(stdout);
	return 0;
}


void qsort(int l,int r){
	int i=l,j=r,mid=a[(i+j)/2];
	int temp;
	do{
		while(a[i]<mid)  i++;
		while(a[j]>mid)  j--;
		if(i<=j){
			temp=a[i]; a[i]=a[j]; a[j]=temp;
			i++;  j--;
		}
	}while(i<=j);
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
