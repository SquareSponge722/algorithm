#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
