#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli parent[100001]; // parent[i]: i が含まれる木の根の番号
lli depth[100001];  // depth[i] : i は自身が含まれる木のどれくらいの深さにいるか(最低1) ただし、根の depth のみが参照される

void init(lli n) {
    REPE(i, 1, n) {
        parent[i] = i;
        depth[i] = 1;
    }
}

lli find(lli x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unite(lli x, lli y) {
    lli x_root = find(x);
    lli y_root = find(y);
    if (x_root == y_root)
        return;

    if (depth[x_root] < depth[y_root]) {
        parent[x_root] = y_root;
    }
    else {
        parent[y_root] = x_root;
        if (depth[x_root] == depth[y_root])
            depth[x_root]++;
    }
}

bool same(lli x, lli y) {
    return find(x) == find(y);
}

int main() {
    lli n = 10;

    // 1〜10 まであるとして、以下のように分けることにする
    // 1,2,3,5,8
    // 4,6,10
    // 7,9

    // 初期化
    init(n);

    // 作成
    unite(1,2);
    unite(2,3);
    unite(3,5);
    unite(1,8);

    unite(4,6);
    unite(4,10);

    unite(7,9);

    // 判定
    cout << "same(1, 5): " << same(1, 5) << " (answer: 1)" << endl;
    cout << "same(1, 6): " << same(1, 6) << " (answer: 0)" << endl;
    cout << "same(4, 6): " << same(4, 6) << " (answer: 1)" << endl;
}
