#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 25005;
int read(){
	char ch=getchar();int x=0,y=1;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*y;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--){
		bool b[N*2];
		int a[105],m[105],maxn=0;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(m,0,sizeof(m));
		a[0]=read();
		for(int i=1;i<=a[0];i++){
			a[i]=read();
			maxn=max(maxn,a[i]); 
		}
		sort(a+1,a+a[0]+1);
		for(int i=1;i<=a[0];i++){
			if(b[a[i]])continue;
			else{
				b[a[i]]=true;
				m[++m[0]]=a[i];
				for(int j=1;j<=maxn;j++){
					if(b[j]){
						int t=j;
						while(t<N){
							t+=a[i];
							b[t]=1;
						}
					}
				}
			}
		}
		cout<<m[0]<<endl;
	}
}
