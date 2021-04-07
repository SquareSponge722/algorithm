# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
# define N 105
int a[N];
int b[N];
int _gcd(int x,int y){
	if(y==0) return x;
	else{
		return _gcd(y,x%y);
	}
}
int T;
int n;
int num;
int ans;
int minn;
int kkk;
int flag;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int h=1;h<=T;h++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		ans=n;
		num=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			if(_gcd(a[1],a[i])==1){
				minn=a[1]*a[i];
				break;
			}
		}
		b[++num]=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>=minn){
				ans--;
			}
			else{
				flag=1;
				kkk=a[i];
				for(int j=num;j>=1;j--){
					a[i]=a[i]%b[j];
					if(a[i]==0){
						flag=0;
						ans--;
						break;
					}
				}
				if(flag==1){
					b[++num]=kkk;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
