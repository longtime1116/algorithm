#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


lli prime[100000];    // i 番目の素数
lli is_prime[100000]; // i 番目が素数かどうか

// n以下の自然数に何個素数が含まれるのかを返す
// sieve(10) => 4
lli sieve(lli n) {
    lli p = 0;
    REPE(i, 0, n) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    REPE(i, 2, n) {
        if (is_prime[i]) {
            prime[p] = i;
            p++;
            for (lli j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

int main() {
    lli n;
    cin >> n;
    lli prime_count = sieve(n);

    REP(i, 0, prime_count) {
        cout << i << ": " << prime[i] << endl;
    }
    REPE(i, 1, n) {
        if (is_prime[i])
            cout << i << ": " << "is prime" << endl;
        else
            cout << i << ": " << "is not prime" << endl;
    }


}
