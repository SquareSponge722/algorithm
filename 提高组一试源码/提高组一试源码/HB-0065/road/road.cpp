#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
long long num;
int ans,t;
int a[100010],s[100010],w[100010];
void wort(int l,int r){
	if(l==r){
		ans+=a[l];
		return ;
	}
	int p=0;
	num=0;
	memset(s,0,sizeof(s));
	memset(w,0,sizeof(w));
	for(int i=l;i<=r+1;i++){
		if(a[i]>s[p]){
			s[++p]=a[i];
			w[p]=1;
		} 
		else{
			int width=0;
			while(s[p]>a[i]){
				width+=w[p];
				if(num <= (long long) s[p]*width){
					num=(long long) s[p]*width;
					t=s[p];
				}
				p--;
			}
			s[++p]=a[i];
			w[p]=width+1;
		}
	}
	ans+=t;
	for(int i=l;i<=r;i++){
		if(a[i]<t) continue;
		a[i]-=t;
	}
	int k=l;
	for(int i=l;i<=r+1;i++){
		if(a[i]==0 && i-1>=k){
			wort(k,i-1);
			k=i+1;
		}
	}
		
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=0;
	num=0;
	wort(1,n);
	printf("%d",ans);
	return 0;
}
