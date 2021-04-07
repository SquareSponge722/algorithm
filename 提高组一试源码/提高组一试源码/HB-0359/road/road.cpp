#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
int a[N]={0},n;
int feng=0,di=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("roac.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]) feng+=a[i];
		if(a[i]<a[i-1]&&a[i]<a[i+1]) di+=a[i];
		if(a[i]>a[i-1]&&a[i]==a[i+1]){
			int j=i;
			while(1){
				j++;
				if(a[j]>a[j+1]){
					feng+=a[j];
					break;
				}
				else if(a[j]<a[j+1]) break;
					else continue;
			}
			i=j;
		}
		if(a[i]<a[i-1]&&a[i]==a[i+1]){
			int j=i;
			while(1){
				j++;
				if(a[j]<a[j+1]){
					di+=a[j];
					break;
				}
				else if(a[j]>a[j+1]) break;
				else continue;
			}
		}
	}
	printf("%d\n",feng-di);
	return 0;
}
