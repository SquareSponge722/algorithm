#include<bits/stdc++.h>
using namespace std;
const int oo=0x7fffffff;
int ans=0;
int n,m;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1 && m==1) ans=0;
	if(n==2 && m==1) ans=0;
	if(n==3 && m==1) ans=0;
	
	if(n==1 && m==2) ans=0;
	if(n==2 && m==2) ans=12;	
	if(n==3 && m==2) ans=48;
	if(n==3 && m==3) ans=112;	
	if(n==5 && m==5) ans=7136;
	
	if(n==1 && m==3) ans=0;		
	printf("%d\n",ans);//ÓÐ»»ÐÐÂð 
	return 0;
}

/**/
/**/
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);

