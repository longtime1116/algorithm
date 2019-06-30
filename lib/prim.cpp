#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

struct edge {
    lli to;
    lli cost;
};

vector<edge> G[100001];
bool used[100001];

lli prim() {

    //// first がその時点での最短経路のコスト、second が頂点の番号
    //priority_queue<P, vector<P>, greater<P>> vque;
    //que.push(P(0, 1));
    //used[0] = true;


    lli total = 0;
    priority_queue< P, vector<P>, greater<P> > que;

    // 事前に最初の node の辺のみ入れておく
    used[1] = true;
    lli cur_v = 1;
    REP(i, 0, (lli)G[cur_v].size()) {
        edge e = G[cur_v][i];
        if (!used[e.to])
            que.push(P(e.cost, e.to));
    }

    // O(ElogV) なのか・・・？
    while (true) {
        // 次に使われる辺を選ぶ
        edge next = {LLONG_MAX, LLONG_MAX};
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            if (!used[p.second]) {
                next.cost = p.first;
                next.to = p.second;
                total += next.cost;
                used[next.to] = true;
                break;
            }
        }
        if (next.cost == LLONG_MAX)
            break;

        // next が使われた辺なので、新たに next.to から張られる辺を登録
        cur_v = next.to;
        REP(i, 0, (lli)G[cur_v].size()) {
            edge e = G[cur_v][i];
            if (!used[e.to])
                que.push(P(e.cost, e.to));
        }
    }

    return total;
}

int main() {
    lli n, m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli a, b, c;
        cin >> a >> b >> c;
        // ここでは無向グラフとする
        edge e1 = {b, c};
        edge e2 = {a, c};
        G[a].push_back(e1);
        G[b].push_back(e2);
    }

    lli ans = prim();
    cout << ans << endl;
}

// 入力例(|V|, |E| からの、始点/終点/コスト)
// 8 15
// 1 8 1
// 7 3 14
// 8 2 13
// 3 5 4
// 5 7 5
// 6 4 1
// 6 8 17
// 7 8 5
// 1 4 2
// 4 7 1
// 6 1 3
// 3 1 10
// 2 6 5
// 2 4 12
// 5 1 30
