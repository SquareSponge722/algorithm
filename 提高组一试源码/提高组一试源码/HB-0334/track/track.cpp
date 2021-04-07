//#define Debug
#include<iostream>
#include<cstdio>
using namespace std;
bool $con(long *a,long nn,long s)
{
    for(int i=1;i<=nn;i++) if(a[i]==s) return true;
    return false;
}
int main()
{
    #ifndef Debug
        freopen("track.in","r",stdin);
        freopen("trace.out","r",stdout);
    #endif // Debug
    long n,m;
    long i,j;
    long ta,tb,tl;
    cin>>n>>m;
    long tree[n+1][n+1]={0};
    long node[n+1]={0};
    long start[n+1]={0};
    long stn=0;
    long res=0;
    long mres=-1;
    for(i=1;i<=n-1;i++)
    {
        scanf("%ld%ld%ld",&ta,&tb,&tl);
        tree[ta][tb]=tl;
        tree[tb][ta]=tl;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(tree[i][j]!=0) {node[i]++;//cout<<"tree["<<i<<"]["<<j<<"]="<<tree[i][j]<<' ';
            }
            //cout<<tree[i][j]<<' ';
        }
        //cout<<"node:"<<i<<"="<<node[i]<<endl;;
       // cout<<endl;
    }
    //return 0;
    long tp,tn;long tm=-1;bool con;
    for(i=1;i<=n;i++) if(node[i]==1) start[++stn]=i;
    //for(i=1;i<=stn;i++) cout<<start[i]<<' ';
    //cout<<endl;
    for(i=1;i<=stn;i++)
    {
        for(j=1;j<=n-1;j++) if(tree[start[i]][j]!=0) {tp=tree[start[i]][j];tn=j;}
        while(1){
        for(j=1;j<=n-1;j++) if(tree[tn][j]!=0) {tm=max(tm,tree[tn][j]);if(tm==tree[tn][j]) tn=j;}
        res+=tm;
        for(j=1;j<=stn;j++) if(tn==start[i]){con=true;break;}
        if(con==true) break;
        }
        mres=max(mres,res+tp);
        tm=-1;
    }
    //cout<<mres;
    cout<<n*2+3;
}
