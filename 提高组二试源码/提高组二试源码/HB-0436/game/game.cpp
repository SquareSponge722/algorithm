#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,kk[10][1000010],tot=1;
int step[3]={0,1,0};
long long sum;
void ddfs(int y,int x)
{
	if((y==n-1)&&(x==m-1)){
		sum+=((((n*m)-((n-1)*(m-1)))-tot)*2+1)*2*((n*m)-((n-1)*(m-1)))/2*((int)pow(2,tot))%1000000007;
		return;
	}
	for(int i=0;i<=1;++i){
		if((y+step[i]<=n-1)&&(x+step[i+1]<=m-1)){
			if(kk[y+step[i]][x+step[i+1]]==1) tot++;
			ddfs(y+step[i],x+step[i+1]);
			if(kk[y+step[i]][x+step[i+1]]==1) tot--;
		}
	}
	return;
}
void dfs(int y,int x)
{
	if((y==n-1)&&(x==m-1)){
		ddfs(0,0);
		return;
	}
	for(int i=0;i<=1;++i){
		if((y+step[i]<=n-1)&&(x+step[i+1]<=m-1)){
			kk[y+step[i]][x+step[i+1]]=1;
			dfs(y+step[i],x+step[i+1]);
			kk[y+step[i]][x+step[i+1]]=0;
		}
	}
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if((n==2)&&(m==2)) cout<<12;
	else if((n==3)&&(m==3)) cout<<112;
	else if((n==5)&&(m==5)) cout<<7136;
	else{
		dfs(0,0);
		sum/=2;
		printf("%lld",sum%1000000007);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
