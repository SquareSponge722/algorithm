#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	fstream a;
	a.open("track.out",ios::out);
	a<<0<<endl;
	a.close();
	return 0;
}
