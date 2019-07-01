#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


// 繰り返し二乗法
// N^p mod m
lli mod_pow(lli n, lli p, lli mod) {
    lli res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * n % mod;
        }
        n = n * n % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    lli n, p, m;

    // 140625001 になるはず
    n = 2;
    p = 1000000000;
    m = 1000000007;
    cout << mod_pow(n, p, m) << endl;
}


// 3^44 mod 10000000
// 44 は 2進数で 101100
// 44 = 32 + 8 + 4
// 3^44 = 3^32 * 3^8 * 3^4



