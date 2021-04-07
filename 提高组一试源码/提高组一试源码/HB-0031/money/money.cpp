#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>

typedef std::vector<int>::iterator Iterator;

int readInt() {
    int res = 0;
    char ch = '*';
    while (!isdigit(ch = getchar()))
        continue;
    do
        res = res * 10 + ch - '0';
    while (isdigit(ch = getchar()));
    return res;
}

int GCD(int x, int y) {
    if (x > y)
        std::swap(x, y);
    while (x != 0) {
        int t = y % x;
        y = x, x = t;
    }
    return y;
}

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int t = readInt();
    while (t--) {
        std::vector<int> vec;
        int n = readInt();
        for (int i = 1; i <= n; ++i)
            vec.push_back(readInt());
        std::sort(vec.begin(), vec.end());
        for (Iterator i = vec.begin(); i != vec.end(); ++i)
        for (Iterator j = i + 1; j != vec.end(); ++j)
            if ((*j) % (*i) == 0)
                vec.erase(j), --j;
        for (Iterator i = vec.begin(); i != vec.end(); ++i)
        for (Iterator j = i + 1; j != vec.end(); ++j) {
            int gcd = GCD(*i, *j);
            int x = (*i) / gcd, y = (*j) / gcd;
            for (Iterator k = j + 1; k != vec.end(); ++k) {
                if ((*k) % gcd != 0)
                    continue;
                int v = (*k) / gcd;
                if (v % x == 0 || v % y == 0 || v > x * y - x - y)
                    vec.erase(k), --k;
            }
        }
        printf("%u\n", vec.size());
    }
    return 0;
}
