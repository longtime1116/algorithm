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
    // 重複を許す場合は multiset
    set<int> s;

    cout << "----- insert-----" << endl;

    s.insert(3);
    cout << "insert: " << 3 << endl;
    s.insert(1);
    cout << "insert: " << 1 << endl;
    s.insert(8);
    cout << "insert: " << 8 << endl;
    s.insert(5);
    cout << "insert: " << 5 << endl;
    s.insert(4);
    cout << "insert: " << 4 << endl;
    s.insert(4); // insert できる値は一意性を持つので、この処理は無視される
    cout << endl;

    cout << "----- dump-----" << endl;
    cout << "iterate" << endl;
    // 小さい順
    REPIT(it, s) {
        cout << *it << endl;
    }
    cout << endl;

    // 大きい順
    cout << "iterate reverse" << endl;
    REPIT_R(it, s) {
        cout << *it << endl;
    }
    cout << endl;

    cout << "----- erase -----" << endl;
    s.erase(4);
    cout << "erase: " << 4 << endl;
    s.erase(8);
    cout << "erase: " << 8 << endl;
    cout << endl;

    cout << "----- dump-----" << endl;
    // 小さい順
    REPIT(it, s) {
        cout << *it << endl;
    }
    cout << endl;


    cout << "----- find -----" << endl;
    cout << "find: " << 3 << endl;
    auto it = s.find(3);
    if (it != s.end())
        cout << *it << endl;
    else
        cout << "not found" << endl;

    cout << "find: " << 4 << endl;
    auto it2 = s.find(4);
    if (it2 != s.end())
        cout << *it2 << endl;
    else
        cout << "not found" << endl;
    cout << endl;


    // lower_bound: 与えられた値よりも小さくない最初の要素へのイテレータ
    // upper_bound: 与えられた値よりも大きい最初の要素へのイテレータ
    // 省略

}
