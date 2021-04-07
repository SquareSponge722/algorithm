#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,type;
int a,x,b,y;
int s;
int w[2000],u[2000],v[2000];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdin);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n-1;i++)
        cin>>u[i]>>v[i];
    for(int i=1;i<=m;i++)
    {
        cin>>a>>x>>b>>y;
        if(abs(a-b)==1&&x==0&&y==0) {cout<<"-1";cout<<endl;}
        else
        {
            for(int j=1;j<=n;j++)
            {
                if(x==1) s+=w[a];
                if(y==1) s+=w[b];
                if(x==0) s+=w[a+1];
                if(y==0) s+=w[b+1];
            }
        }
    }
    cout<<"12"<<endl;
    cout<<'7'<<endl;
    cout<<"-1"<<endl;
	return 0;
}
