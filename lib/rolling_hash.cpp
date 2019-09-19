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

// [用語解説]
// H(l, r) := l 文字目から r-1 文字目までの(r-l)文字のハッシュ値
// S: n文字からなる文字列。
// si: i 文字目の文字
// ci: i 文字目の文字に対応する数値(文字コードを使えば良い)
// b: 基数
//
// [ハッシュ関数の定義は？]
// H(0,n) = c0*b^(n-1) + c1*b^(n-2) + c2*b^(n-3) + ... + cn-2*b^1 + cn-1*b^0
//
// [どのようにして任意の部分文字列のハッシュ値を取得するか]
// H(1, i) を事前計算する(iは0からn-1までの整数)
// すると、以下のように H(l, r) を求めることができる
// H(l, r) := H(0, r) - b^(r-l)*H(0,l)
//
// [例]
// 以下のような例を考える
// S: "abxcabx"
// b: 10
// また、それぞれの文字に対応する数値は以下のようになっているとする。
// {a: 1, b: 2, c: 3, x: 20}
//
// H(0,1):       1 <= 1*10^0
// H(0,2):      12 <= 1*10^1 + 2*10^0
// H(0,3):     140 <= 1*10^2 + 2*10^1 + 20*10^0
// H(0,4):    1403 <= 1*10^3 + 2*10^2 + 20*10^1 + 3*10^0
// H(0,5):   14031 <= 1*10^4 + 2*10^3 + 20*10^2 + 3*10^1 + 1*10^0
// H(0,6):  140312 <= 1*10^5 + 2*10^4 + 20*10^3 + 3*10^2 + 1*10^1 + 2*10^0
// H(0,7): 1403140 <= 1*10^6 + 2*10^5 + 20*10^4 + 3*10^3 + 1*10^2 + 2*10^1 + 20*10^0
//
// H(0,4) と H(4,7) が等しいことを確認する
// H(0,4): 140
// H(4,7): H(0,7) - 10^2+H(0,4) = 1403140 - 140300 = 140
//
// [注意]
// 以下の実装では、1文字目から基数を掛けている(b^0ではなくb^1)


struct RollingHash {
    static const int base = 1007;
    static const int mod = 1000000007;
    // another version
    //static const int base = 2009;
    //static const int mod = 1000000009;

    vector<lli> hash, power;

    RollingHash(const string &S) {
        lli n = S.size();
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        REP(i,0,n) {
            hash[i+1] = (hash[i] * base + S[i]) % mod;
            power[i+1] = (power[i] * base) % mod;
        }
    }

    // get hash value of S[left:right]
    lli get(lli l, lli r) {
        lli ret = hash[r] - hash[l] * power[r-l] % mod;
        if (ret < 0)
            ret += mod;
        return ret;
    }

    // get lcp of S[i:] and S[j:]
    lli get_lcp(lli i, lli j) {
        lli low = 0;
        lli high = hash.size() - max(i, j);

        while (high - low > 1) {
            lli mid = (low + high) / 2;
            if (get(i, i+mid) == get(j, j+mid)) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    string s = "abxcabxab";
    string t = "abx";
    lli len = t.length();

    cout << "find " << t << " from " << s << endl;

    RollingHash rh(s);
    REP(i,0,s.length()-len+1) {
        if (rh.get(i, i + len) == rh.get(0,len)){
            cout1(i);
            //cout << s.substr(i, len) << endl;
        }
    }
    cout << "get LCP" << endl;
    REP(i,0,s.length()) {
        cout << rh.get_lcp(0, i) << ", ";
    }
    cout << endl;
}

