#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin >> n;
    // 素因数 key が value 個ある、を表す map
    map<lli, lli> fac;
    lli num = n;
    for(lli i = 2; i*i<=num; i++) {
        while (num % i == 0) {
            fac[i]++;
            num /= i;
        }
    }
    if (num != 1)
        fac[num] = 1;
    REPIT(it, fac) {
        cout << it->first << ": " << it->second << endl;
    }
}
