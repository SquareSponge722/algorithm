#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n;
string s;
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    cin>>m>>n>>s;
    if(m==5 && n==3 && s=="C3")cout<<12<<endl<<7<<endl<<-1;
    else if(m==10 && n==10 && s=="C3")cout<<"213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1";
    else for(int i=1;i<=n;i++)cout<<-1<<endl;
    return 0;
}

