#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("road.in");
    ofstream fout("road.out");
    int n;
    fin >> n;
    int h[100001];
    for(register int i = 1; i <= n; i++) {
        fin >> h[i];
    }

    int ans = 0;
    bool started = false;
    do {
        started = false;

        int s = 0, end = 0;
        int MIN = 9999999;
        for(register int i = 1; i <= n; i++) {
            if(h[i] == 0 && !started) {
                continue;
            }
            if(!started) {
                started = true;
                s = i;
            }
            if(h[i] < MIN) {
            	int xx = MIN - h[i];
            	MIN = h[i];
            	for(register int j = s; j < i; j++) {
            		h[j] += xx;
				}
			}
			h[i] -= MIN;
            if(i < n && h[i + 1] == 0) {
                end = i;
                break;
            }
        }
        if(started) {
            ans += MIN;
        }

    } while (started);
    fout << ans;
    return 0;
}
