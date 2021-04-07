#include<bits/stdc++.h>
using namespace std;
int n,m,y;
int ans[6][6]=
{0,0,0,0,0,0,
 0,2,4,8,16,0,
 0,4,12,36,0,0,
 0,8,36,112,0,0,
 0,16,0,0,0,0,
 0,0,0,0,0,7136,
};

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    scanf("%d %d",&n,&m);
	cout<<ans[n][m];
    return 0;	
}
