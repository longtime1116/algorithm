#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;




// <解説>
// ax + py = 1 を満たす x を a の逆元と呼ぶ
// p = qa + r として式変形する
//
//      qax + qpy = q
//  <=> (p-r)x + qpy = q
//  <=> rx + p(-x-qy) = -q ・・・ (1)
//
// さて、rx + pz = 1 を満たすx,zをs,tとすると、
//      rs + pt = 1
// と表せる。この両辺を q 倍すると、
//      r(-sq) + p(-tq) = -q ・・・ (2)
//
// ここで (1) と (2) を比べてみると、x = -sq は a の逆元となっていることがわかる
// s は定義より r の逆元であり、q は定義より p を a で割った商となっている
// したがって、
//      x = -sq
//        = r^-1 * (p/a)

const lli MOD = 1000000007;
const lli MAX = 1000001;
lli fac[MAX];       // fac[i]     := iの階乗 % MOD
lli fac_inv[MAX];   // fac_inv[i] := iの階乗の逆元 % MOD (すなわち、fac[i]*fac_inv[i] % MOD == 1)
lli inv[MAX];       // inv[i]     := iの逆元 (すなわち、i*inv[i] % mod == 1)

void init_comb_base() {
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;
    inv[1] = 1;
    REP(i,2,MAX) {
        fac[i] = i * fac[i-1] % MOD; // n! = n * (n-1)! % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD; // ↑の解説参照
        fac_inv[i] = inv[i] * fac_inv[i-1] % MOD; // n! = n * (n-1)! % MOD
    }
}

lli comb(lli n, lli k) {
    if (n<k)
        return 0;
    if (n < 0 || k < 0)
        return 0;

    // nCk = n! / (k! * (n-k)!)
    //     = n! * (k!)^-1 * ((n-k)!)^-1
    return fac[n] * (fac_inv[k] * fac_inv[n-k] % MOD) % MOD;
}

int main() {
    init_comb_base();
    cout << "4C1: " << comb(4, 1) << endl;
    cout << "4C2: " << comb(4, 2) << endl;
    cout << "8C3: " << comb(8, 3) << endl;
    cout << "200C100: " << comb(200, 100) << endl;
    cout << "100000C50000: " << comb(100000, 50000) << endl;
}


