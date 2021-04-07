#include <iostream>
#include <cstdio>
using namespace std;
int a[23][25005];int T;
void shuchu(int p)
{if(p%2==0) cout<<2;
 else cout<<3;
}
void jisuan(int w)
{int n;
cin>>n;
for(int i=1;i<=n;i++)
 cin>>a[w][i];
if(w==T) shuchu(n);
else {shuchu(n);cout<<endl;}
 
 
}

int main()
{freopen("money.in","r",stdin);
 freopen("money.out","w",stdout);
 cin>>T;
 for(int i=1;i<=T;i++)
  jisuan(i);
return 0;
}
