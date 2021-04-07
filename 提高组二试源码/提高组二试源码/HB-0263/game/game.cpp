#include<cstdio>//AFO
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int a[5][5];
int n,m,sum=0;
string mn,now="";
bool check(int x,int y)
{
    now+='0'+a[x][y];
    if(x==n&&y==m)
    {
        if(now<=mn)
        {
            mn=now;
            return true;
        }
        else
            return false;
    }

    bool ans=1;
    if(y<m)
        ans&=check(x,y+1);
    if(x<n)
        ans&=check(x+1,y);
    now=now.substr(0,x+y-2);
    return ans;
}
void dfs(int x,int y)
{
    if(y>m)
    {
        if(x==n)
        {
            mn="1111111";
            sum+=check(1,1);
            return;
        }
        return dfs(x+1,1);
    }
    a[x][y]=0;
    dfs(x,y+1);
    a[x][y]=1;
    dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    dfs(1,1);
    printf("%d\n",sum);
}

