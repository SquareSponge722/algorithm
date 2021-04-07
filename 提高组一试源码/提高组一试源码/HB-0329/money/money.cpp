#include<cstdio>
#include<iostream>
#include<algorithm>
#define For(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
int a[105];
bool book[105];

int read(){
	int p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

bool gcd(int x,int y,int z){
	for(int tx=0;tx<=z/x;tx++)
	for(int ty=0;ty<=z/y;ty++){
	 if(tx*x+ty*y==z)return 1;
	 if(tx*x+ty*y>z)break;} 
	return 0;
}

bool Gcd(int x,int y,int z,int w){
	for(int tx=0;tx<=w/x;tx++)
	for(int ty=0;ty<=w/y;ty++)
	for(int tz=0;tz<=w/z;tz++){
	 if(tx*x+ty*y+tz*z==w)return 1;
	 if(tx*x+ty*y+tz*z>w)break;} 
	return 0;
}

int main()
{	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,ans,num;
	T=read();
	For(i,1,T){
		n=read();ans=n;
		if(n==2){
			a[1]=read();a[2]=read();
			if(a[1]>a[2])swap(a[1],a[2]);
			if(a[2]%a[1]==0)cout<<1<<endl;
			else cout<<2<<endl;
		}
		else{
			For(j,1,n)book[j]=0;
		    For(j,1,n)a[j]=read();
		    sort(a+1,a+n+1);
		    For(j,2,n){
			    For(k,1,j-1){
				    if(!book[k]){
					    For(l,1,j-1)
					    {
						    if(!book[l]){
			        	        For(r,1,j-1)
			        	        if(!book[r]&&Gcd(a[k],a[l],a[r],a[j])){
			        		        ans--;
			        		        book[j]=1;
			        		        break;
						        }
					        }
					    if(book[j])break;
					    }
				    }
				    if(book[j])break;
			    }
		    }
		    printf("%d\n",ans);
		}
	}
	return 0;
}
