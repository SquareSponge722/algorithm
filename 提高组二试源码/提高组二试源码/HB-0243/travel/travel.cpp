#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int mm=5050;
int n,m;
priority_queue<int,vector<int>,greater<int> >mat[mm];
vector<int> ma[mm];
queue<int>q;
int vis[mm];
int ansvis[mm];
int a[mm];
int tot;
int flag;
int k;
void dfs(int pos)
{
    //cout<<pos<<endl;
    if(flag==1)return;
    if(ansvis[pos]==0){a[++tot]=pos;ansvis[pos]=1;k++;}
    if(k==n){flag=1;return;}
    for(int i=0;i<ma[pos].size();i++)
    {
        int tp=ma[pos][i];
        //mat[pos].pop();
        if(vis[tp]!=1)
        {
            vis[tp]=1;
        dfs(tp);
        vis[tp]=0;
        }
    }
}
//void dfs(int )
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        mat[x].push(y);
        mat[y].push(x);
    }
    for(int i=1;i<=n;i++)
    {
        while(!mat[i].empty())
        {
            int t=mat[i].top();
            ma[i].push_back(t);
            //cout<<t<<' ';
            mat[i].pop();
        }
        //cout<<endl;
    }
    //return 0;
    if(m==n-1)
    {
        vis[1]=1;
        dfs(1);
    for(int i=1;i<=tot;i++)
        cout<<a[i]<<' ';
        return 0;
    }
    else
    {
        a[++tot]=1;
        a[++tot]=ma[1][0];
        vis[1]=1;
        vis[ma[1][0]]=1;
        k=n-2;
        int pp=1;
        int temp=ma[1][1];
        if(ma[ma[1][0]][1]>temp)
            pp=temp;
            else
            {
                int t=ma[ma[1][0]][0];
                if(t==1)pp=ma[ma[1][0]][1];
                else
                    pp=t;
            }
        while(k--)
        {
            a[++tot]=pp;
            vis[pp]=1;
            int t=ma[pp][0];
            if(vis[t]==1){pp=ma[pp][1];}
            else
                pp=t;
            //vis[]
        }
        for(int i=1;i<=tot;i++)
        {
            cout<<a[i]<<' ';
        }
        return 0;
    }
    //q.push(1);
    //vis[1]=1;
    /*while(!q.empty())
    {
        int top=q.front();
        //a[++tot]=top;
        //vis[top]
        while(!mat[top].empty())
        {
            int tp=mat[top].top();

            q.push(tp);
        }
    }*/

    return 0;
}
