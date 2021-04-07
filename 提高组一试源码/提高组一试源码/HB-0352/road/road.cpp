#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
const int N = 100005;
struct node
{
	int x,id;
	bool operator <(const node &a)const {return x<a.x;}
}a[N],b[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=rd();
	long long sum=0;
	for (int i=1;i<=n;i++)
	{
		a[i].x=rd();
		a[i].id=i;
		sum+=a[i].x;
		b[i].x=a[i].x;
		b[i].id=i;
	}
	sort(a+1,a+n+1);
//	for (int i=1;i<=n;i++) cout<<a[i].id<<' '<<a[i].x<<endl;
	long long ans=0;
	int l,r;
	for (int i=1,t;i<=n;i++)
	{
		if (b[a[i].id].x)
		{
			t=b[a[i].id].x;
			sum-=t;
			b[a[i].id].x=0;
			l=a[i].id+1;
			while (l<=n && b[l].x) b[l].x-=t,l++;
			r=a[i].id-1;
			while (1<=r && b[r].x) b[r].x-=t,r--;
			ans+=t;
		}
		else continue;
		if (sum==0) break;
	}
	cout<<ans<<endl;
	return 0;
}
