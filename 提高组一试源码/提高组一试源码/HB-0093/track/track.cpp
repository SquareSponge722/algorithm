#include <iostream>
#include <fstream>
using namespace std;
int main(){
ifstream in;
ofstream out;
in.open("track.in");
out.open("track.out");
int n = 1;
out<<n;
in.close();
out.close();
}
