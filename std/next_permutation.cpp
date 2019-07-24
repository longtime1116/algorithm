#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli a[] = {1, 3, 2};
    lli b[] = {1, 2, 2};
    lli n = 3;

    // sort で昇順になっていることが条件
    sort(a, a+n);
    do {
        cout << "[" << a[0] << ", " << a[1] << ", " << a[2] << "]" << endl;;

    } while (next_permutation(a, a+n));

    // 同一の要素があっても動く
    sort(b, b+n);
    do {
        cout << "[" << b[0] << ", " << b[1] << ", " << b[2] << "]" << endl;;

    } while (next_permutation(b, b+n));


}

//[1, 2, 3]
//[1, 3, 2]
//[2, 1, 3]
//[2, 3, 1]
//[3, 1, 2]
//[3, 2, 1]

//[1, 2, 2]
//[2, 1, 2]
//[2, 2, 1]
