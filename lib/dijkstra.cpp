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
lli d[100001];
lli n;
lli prev_v[100001]; // 経路復元用

void dijkstra(lli start) {
    REPE(i, 1, n) {
        d[i] = LLONG_MAX;
    }
    d[start] = 0;
    prev_v[start] = start;

    // first がその時点での最短経路のコスト、second が頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        lli cur_v = p.second;
        // もっと短い経路が既に登録されていたら、このpopしたやつは無視してよい
        if (d[cur_v] < p.first) {
            continue;
        }
        // cur_v の辺を周って、更新しつつ queue に push していく
        REP(i, 0, (lli)G[cur_v].size()) {
            edge e = G[cur_v][i];
            if (d[e.to] > d[cur_v] + e.cost) {
                d[e.to] = d[cur_v] + e.cost;
                que.push(P(d[e.to], e.to));
                prev_v[e.to] = cur_v;
            }
        }
    }
}

int main() {
    lli m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli a, b, c;
        cin >> a >> b >> c;
        edge e = {b, c};
        G[a].push_back(e);
    }
    lli start = 1;

    dijkstra(start);
    cout << "----- 最短距離 -----" << endl;
    REPE(i, 1, n) {
        cout << "d[" << i << "]: " << d[i] << endl;
    }
    // 1〜n それぞれの経路を出力
    cout << "----- 最短経路とその距離 -----" << endl;
    REPE(i, 1, n) {
        lli cur = i;
        cout << i << " -> ";
        while(true) {
            cur = prev_v[cur];
            if (cur == start) {
                cout << start << " (" << d[i] << ")" << endl;
                break;
            }
            cout << cur << " -> ";
        }
    }
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
