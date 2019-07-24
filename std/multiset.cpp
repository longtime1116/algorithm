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
    lli values[] = {1, 2, 2, 3, 5, 6, 7, 7};
    multiset<lli> s(values, values + 8);

    // multiset は重複を許す
    REPIT(it, s) {
        cout << *it << ", ";
    }
    cout << endl;

    // 二分探索するとき、STLのものを使うとO(n)になってしまう！
    auto it1 = lower_bound(s.begin(), s.end(), 3);
    cout << *it1 << endl;
    auto it2 = upper_bound(s.begin(), s.end(), 3);
    cout << *it2 << endl;
    cout << endl;

    // multiset のインスタンスにメッセージを送れば O(logn)
    auto it3 = s.lower_bound(3);
    cout << *it1 << endl;
    auto it4 = s.upper_bound(3);
    cout << *it2 << endl;
    cout << endl;

    // ひとつだけ消す
    auto it_erase1 = s.find(2);
    s.erase(it_erase1);
    // 全部消す
    auto it_erase2 = s.find(7);
    s.erase(*it_erase2);
    REPIT(it, s) {
        cout << *it << ", ";
    }
    cout << endl;

}
