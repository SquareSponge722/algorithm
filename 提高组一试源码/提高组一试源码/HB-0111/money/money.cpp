#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("money.in");
    ofstream fout("money.out");
    int t, n;
    fin >> t;
    register int i = 0;
    for(; i < t; i++) {
        fin >> n;
        int v[n];
        int temp[n];
        int p = 1;
        for(register int j = 0; j < n; j++) {
            fin >> v[j];
        }
        sort(v, v+n);
        temp[0] = v[0];
        for(register int j = 1; j < n; j++) {
            int ans = v[j];
            int s[1320];
            int spp = 1;
            s[0] = v[j];

            for(int k = p - 1; k >= 0; k--) {
                for(int sp = 0; sp < spp; sp++) {

                    int offset = s[sp] / temp[k];
                    int modd = s[sp] % temp[k];
                    if(modd == 0) {
                        ans = 0;
                        k = -1;
                        break;
                    } else if(sp == 0) {
                        while(offset >= 0) {
                            s[spp] = modd + temp[k] * offset;

                            spp++;
                            offset--;
                        }
                    }

                }
            }


            if(ans != 0) {
                temp[p] = v[j];
                p++;
            }
        }
//        fout << "[";
//        for(int aa = 0; aa < p; aa++) {
//            fout << temp[aa] << " ";
//        }
//        fout << "]";
        fout << min(n, p);
        if(i != t-1) {
        	fout << endl;
		}
    }

    return 0;
}
