#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;

inline long long read(){
	
	long long x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
	
}

long long t;

int main(){
	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--){
		
		long long cnt=0,maxx=0,minn=1e5,n,a[105],ans,b[105];
		int use[25005]={0};
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			minn=min(minn,a[i]);
			maxx=max(maxx,a[i]);
			use[a[i]]=1;
		}
		sort(a+1,a+n+1);
		
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
				if(!(a[i]%a[j]))
					use[a[i]]=2;
				
				
		for(int i=minn;i<=maxx;i++){
			if(use[i]==1){
				cnt++;
				b[cnt]=i;
			}
		}
		ans=cnt;
		
		sort(b+1,b+1+cnt);
		if(ans==2){
			cout<<2<<endl;
		}
		else if(ans==3){
			int x=b[3];
			while(x>=b[1]){
				x-=b[2];
				if(!(x%b[1])){
					ans--;
					break;
				}
			}
			cout<<ans<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
