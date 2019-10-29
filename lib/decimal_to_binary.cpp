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


void decimal_to_binary(vector<char>& ret, lli n, lli base) {
    lli cur = 1;
    while (n != 0) {
        if (n % (cur * 2) == 0) {
            ret.push_back('0');
        }
        else {
            ret.push_back('1');
            n -= cur;
        }
        cur *= base;
    }
    if (ret.size() == 0)
        ret.push_back('0');
}

int main() {
    lli n;

    // 10100: 20
    // ↑これが4でわれるのは、下位2bitが全部ゼロだから
    // ある n bit 目をチェックするとき、その bit より下位の bit は全て 0 だとすると、
    // base^(n-1) を 2 倍したもので割り、余りが0でなかったらbitが立っているということ。

    n = 9;
    lli base = 2;
    vector<char> ans;
    decimal_to_binary(ans, n, base);
    cout << "base: " << n << endl;
    cout << "base: 2, n: 9" << endl;
    REPE_R(i,ans.size()-1, 0) {
        cout << ans[i];
    }
    cout << endl;

    // -2進数
    // ABC105 C
    n = -9;
    base = -2;
    vector<char> ans2;
    decimal_to_binary(ans2, n, base);
    cout << "base: -2, n: " << n << endl;
    REPE_R(i,ans2.size()-1, 0) {
        cout << ans2[i];
    }
    cout << endl;

}
