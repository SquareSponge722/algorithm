# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
int f[1000000];
inline int read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-48;
	return res;
}
int T,n,val[150],temp[150],cant[10000],cnt,book[150];
int main (){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	for(int tt=1;tt<=T;++tt){
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		memset(cant,0,sizeof(cant));
		memset(book,0,sizeof(book));
		n=read();
		cnt=n;
		for(int i=1;i<=n;++i)	val[i]=read();
		if(n==2){
			if(val[1]*val[2]-val[1]-val[2]<=0||val[2]%val[1]==0||val[1]%val[2]==0)	cout<<1<<endl;
			else cout<<2<<endl;
		}
		else {
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j){
					if((val[i]%val[j])==0&&i!=j)	book[i]=1;
				}//可以被替代
			for(int i=1;i<=n;++i)	if(book[i])	cnt--,val[i]=0;
			
			if(cnt==0)	cout<<1<<endl;
			
			else if(cnt==1)	cout<<1<<endl;
			
			else if(cnt==2){
				if(val[1]*val[2]-val[1]-val[2]<=0)	cout<<1<<endl;
				else cout<<2<<endl;
			}
			else if(cnt==3){
				sort(val+1,val+1+n);
				for(int i=1;i<=1000;++i){
					for(int j=1;j<=1000;++j){
						if(val[n-2]*i+val[n-1]*j==val[n])	{
						cnt=2;
						break;}
					}
				}
				if(cnt==3)	cout<<3<<endl;
				else if(cnt==2){
					if(val[n-2]*val[n-1]-val[n-2]-val[n-1]<=0)	cout<<1<<endl;
					else cout<<2<<endl;
				}
				else cout<<1<<endl;
			}
			else if(cnt==4){
				sort(val+1,val+1+n);
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-1]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-2]*i+val[n-1]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-2]*j==val[n-1])	{
							cnt--; val[n-1]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-2]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				if(cnt==4)	cout<<4<<endl;
				else if(cnt==3)	cout<<3<<endl;
				else if(cnt==2){
					if(val[n-2]*val[n-1]-val[n-2]-val[n-1]<=0)	cout<<1<<endl;
					else cout<<2<<endl;
				}
				else cout<<1<<endl;
			}
			else if(cnt==5){
				sort(val+1,val+1+n);
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-1]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-4]*i+val[n-1]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-2]*i+val[n-1]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-2]*j==val[n-1])	{
							cnt--; val[n-1]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-4]*i+val[n-2]*j==val[n-1])	{
							cnt--; val[n-1]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-3]*i+val[n-2]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-4]*i+val[n-2]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-4]*i+val[n-3]*j==val[n])	{
							cnt--; val[n]=0;
							break;
						}
					}
				for(int i=1;i<=1000;++i)
					for(int j=1;j<=1000;++j){
						if(val[n-4]*i+val[n-3]*j==val[n-2])	{
							cnt--; val[n-2]=0;
							break;
						}
					}
				if(cnt==5)	cout<<5<<endl;
				else if(cnt==4)	cout<<4<<endl;
				else if(cnt==3)	cout<<3<<endl;
				else if(cnt==2){
					if(val[n-2]*val[n-1]-val[n-2]-val[n-1]<=0)	cout<<1<<endl;
					else cout<<2<<endl;
				}
				else cout<<1<<endl;
			}
		}
	}
	return 0;
}
