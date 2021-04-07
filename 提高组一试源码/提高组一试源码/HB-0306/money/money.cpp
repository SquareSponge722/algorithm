#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
const int maxn=100+10,maxa=25000+10;
int a[maxn],b[maxn],n,m,t;
bool del[maxn],del2[maxa];
int c[maxn];
int gcd(int x,int y){
	if(x<y)swap(x,y);
	return y==0?x:gcd(y,x%y);
}
int xiaokai(int x,int y){
	int g=gcd(x,y);
	x/=g;
	y/=g;
	return (x*y-x-y)*g;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(del,0,sizeof(del));
		memset(del2,0,sizeof(del2));
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(a[j]%a[i]==0)del[j]=1;
		int m=0;
		for(int i=1;i<=n;i++)
		if(!del[i])b[++m]=a[i];
		int mini=xiaokai(b[1],b[2]);
		if(mini<=b[m]){
		int ins=lower_bound(b+1,b+n+1,mini)-b;
		m=ins;
	}
    for(int k=0;k*b[1]<b[m];k++)
    c[k*b[1]]=1;
    for(int i=2;i<=m;i++){
    	for(int j=0;j<=b[m];j++)
		if(c[j]){
			for(int k=1;j+b[i]*k<=b[m];k++){
				if(j!=0)del2[j+b[i]*k]=1;
				c[j+b[i]*k]=1;
			}
		}
	}
	int M=0;
	for(int i=1;i<=m;i++)
	if(!del2[b[i]])M++;
	if(M>n)M=n;
	printf("%d\n",M);
}
return 0;
}
