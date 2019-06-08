#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


vector<lli> G[100001];
lli colors[100001];

lli is_bipartite(lli target, lli color) {
    colors[target] = color;
    REP(i, 0, (lli)G[target].size()) {
        lli next = G[target][i];
        if (colors[next] == -color) {
            // 別の色で既に塗られている。それが塗られたときは二部グラフだったはずで、
            // ここで target を塗ったとしても矛盾するわけではないのでスキップ
            continue;
        }
        else if (colors[next] == color) {
            // 同一色で既に塗られているのでアウト
            return false;
        }
        else if (!is_bipartite(next, -color)) {
            // まだ塗られていないので、next 以降にゆだねている
            return false;
        }
    }
    return true;
}

int main() {
    G[1].push_back(2);
    G[2].push_back(1);

    G[2].push_back(3);
    G[3].push_back(2);

    G[3].push_back(4);
    G[4].push_back(3);

    G[4].push_back(5);
    G[5].push_back(4);

    G[5].push_back(6);
    G[6].push_back(5);

    // ↓のコメントアウトを消すと奇サイクルが生まれ、二部グラフではなくなる
    //G[4].push_back(6);
    //G[6].push_back(4);

    if (is_bipartite(1, 1)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
