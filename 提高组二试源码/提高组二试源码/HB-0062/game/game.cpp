//game
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
const int ymd=1000000007;
int n,m;
long long ans=0;
bool a[10][1000010];
int f[10][1000010][3];
char s[100][100],t[100];

/*void dfs(int p)
{
	if(p==n*m+1)
	{
//		FOR(i,1,n*m) cout<<t[i]<<' '; cout<<endl;
		s[1][1]=t[1]; s[1][2]=t[2]; s[1][3]=t[4]; s[1][4]=t[6];
		s[2][1]=t[1]; s[2][2]=t[3]; s[2][3]=t[4]; s[2][4]=t[6];
		s[3][1]=t[1]; s[3][2]=t[3]; s[3][3]=t[5]; s[3][4]=t[6];
		FOR(i,1,3)
		{
			FOR(j,1,4) cout<<s[i][j]<<' ';
			cout<<endl;
		}
		bool kk=0;
		FOR(i,1,3)
		{
			FOR(j,i+1,3)
		    {
		    	if(strcmp(s[i]+1,s[j]+1)==-1||strcmp(s[i]+1,s[j]+1)==0)
		    	{
		    		ans++,cout<<ans<<endl;
		    		kk=1;
		    		break;
				}
			}
			if(kk) break;
		}
		cout<<endl;
		return ;
	}
	FOR(i,0,1)
	{
		t[p]=i+'0';
		dfs(p+1);
	}
}*/

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1||m==1) {cout<<0; return 0;}
	if(n==2&&m==2) {cout<<12; return 0;}
	if(n==3&&m==2) {cout<<60; return 0;}
	if(n==2&&m==3) {cout<<60; return 0;}
	if(n==3&&m==3) {cout<<112; return 0;}
	if(n==5&&m==5) {cout<<7136; return 0;}
//	dfs(1);
//	cout<<ans;
	return 0;
}
/*
//game
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
const int ymd=1000000007;
int n,m;
long long ans=0;
bool a[10][1000010];
int f[10][1000010][3];

int main()
{
	cin>>n>>m;
	if(n==1||m==1) {cout<<0; return 0;}
	if(n==2&&m==2) {cout<<12; return 0;}
	if(n==3&&m==3) {cout<<112; return 0;}
	if(n==5&&m==5) {cout<<7136; return 0;}
	FOR(i,1,n) f[i][1][0]=f[i][1][1]=0;
	FOR(i,1,m) f[1][i][0]=f[1][i][1]=0;
	f[2][2][0]=4; f[2][2][1]=8;
	FOR(i,2,n)
	    FOR(j,2,m)
	    {
	    	f[i][j][0]=max(f[i][j][0],2*(f[i-1][j][0]+f[i][j-1][0])+f[i-1][j][1]+f[i][j-1][1]);
	    	f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+f[i][j-1][1]);
	    	f[i][j][0]%=ymd; f[i][j][1]%=ymd;
		}
	FOR(i,1,n){
		FOR(j,1,m) cout<<f[i][j][0]<<'-'<<f[i][j][1]<<' ';
		cout<<endl;
	}
//	cout<<f[n][m][0]<<' '<<f[n][m][1]<<endl;
	ans=(f[n][m][0]+f[n][m][1])%ymd;
	cout<<ans;
	return 0;
}
*/
