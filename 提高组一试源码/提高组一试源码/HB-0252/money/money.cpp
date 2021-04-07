#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int T,N;
int m[105];
bool book[30000];
int can[30000],nc;
int ans;
int main()  {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--)  {
		cin>>N;
		for(int i=1;i<=N;i++)  {
			cin>>m[i];
		}
		sort(m+1,m+N+1);
		if(N==2)  {
			if(m[2]%m[1]==0)  {
				cout<<1<<endl;
			}
			else  cout<<2<<endl;
			continue;
		}
		else if(N>=3)  {
			ans=N;
			memset(book,0,sizeof(book));
			nc=1;
			can[nc]=0;
			for(int i=1;i<=N;i++)  {
				if(book[m[i]])  {
					ans--;
					continue;
				}
				for(int j=1;j<=nc;j++)  {
					for(int k=1;m[i]*k+can[j]<=m[N];k++)  {
						if(book[m[i]*k+can[j]])  continue;
						book[m[i]*k+can[j]]=1;
						can[++nc]=m[i]*k+can[j];
					}
				}
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}
