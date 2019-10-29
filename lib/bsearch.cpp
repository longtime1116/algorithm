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


// f(target, cur) target よりも cur が大きければtrue
inline bool f(lli target, lli cur) {
    return target < cur;
}

// 1以上100以下の値をとる整数が単調増加して並ぶ数列があるとする。
// 1以上100以下の値をとる整数 target よりも大きい最初の値を見つける
// あるなら "Yes"、なければ "No" を返す
int main() {
    // a の最初と最後 に番兵を入れておく
    lli a[] = {0, 2, 3, 5, 7, 8, 9, 11, 13, 101};
    lli target = 8;

    // left には、必ず f(left) が false となる値を入れる。
    // right には、必ず f(right) が true となる値を入れる。
    lli left = 0;
    lli right = ARRAY_LENGTH(a)-1;
    while (right - left > 1) {
        lli cur = (left+right)/2;

        // この評価関数の部分を文脈に合わせて変える
        bool is_ok = f(target, a[cur]);
        cout3(target, a[cur], f(target, a[cur]));

        if (is_ok) {
            right = cur;
        }
        else {
            left = cur;
        }
    }
    lli ans = a[right];
    cout1(ans);
}
