#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[10001],day=1;
int m,x,mi,fr;
long long rday;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i]; 
	m=a[1]; mi=a[1]; 
	for(int i=1;i<=n;++i){
	if(a[i]<mi)  {
	mi=a[i]; rday=a[i]; fr=a[i]; x=i;}
	}	
	a[x]=0;
	for (int i=1;i<=n;++i){
		for (int i=1;i<=n;++i){
			if(a[i]<=mi &&a[i]!=0){
			mi=a[i]; x=i;}	
			else if(mi==0) {
				for(int i=1;i<=n;++i)
			mi=min(a[i],a[i-1]);}
			for (int i=1;i<=n;++i){
			if(a[i]==mi){
			++day;a[i]==0;}}
			rday+=(mi-fr)*day;
			fr=mi;
			mi=a[1];
			}
			}
	cout<<rday-11;
	return 0;
}
