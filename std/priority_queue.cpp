#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

//
// std::priority_queue
// namespace std {
//   template <class T,
//             class Container = std::vector<T>,
//             class Compare = less<typename Container::value_type>>
//   class priority_queue;
// }
//
// デフォルト値
//   Container: コンテナとして型 T の動的配列を使う
//   Compare: Container の値で比較して、less なものを残す(greater を指定すると逆になる)
//

class CompareDist
{
public:
    bool operator()(P n1, P n2) {
        return n1.second>n2.second;
    }
};
int main() {
    int numbers[] = {5, 3, 8, 5};

    // 大きい順(デフォルト)
    priority_queue<int> que1;
    cout << "# default Compare(the largest one is poped)" << endl;
    cout << "----- input -----" << endl;
    REP(i, 0, ARRAY_LENGTH(numbers)) {
        que1.push(numbers[i]);
        cout << numbers[i] << " is pushed" << endl;
    }

    cout << "----- output -----" << endl;
    while (!que1.empty()) {
        cout << que1.top() << " is poped";
        que1.pop();
        cout << " (size: " <<  que1.size() << ")" << endl;
    }
    cout << endl;

    // 小さい順
    priority_queue<int, vector<int>, greater<int>> que2;
    cout << "# changed Compare(the smallest one is poped)" << endl;
    cout << "----- input -----" << endl;
    REP(i, 0, ARRAY_LENGTH(numbers)) {
        que2.push(numbers[i]);
        cout << numbers[i] << " is pushed" << endl;
    }

    cout << "----- output -----" << endl;
    while (!que2.empty()) {
        cout << que2.top() << " is poped";
        que2.pop();
        cout << " (size: " <<  que2.size() << ")" << endl;
    }
    cout << endl;


    // pair の後ろの値での比較(小さい順にpop)
    P p[] = {P(1, 2), P(5, 1), P(3, 4)};
    priority_queue< P, vector<P>, CompareDist > que3;
    cout << "# the priority_queue of pair" << endl;
    cout << "----- input -----" << endl;
    REP(i, 0, ARRAY_LENGTH(p)) {
        que3.push(p[i]);
        cout << "(" << p[i].first << ", " << p[i].second  <<") is pushed" << endl;
    }

    cout << "----- output -----" << endl;
    while (!que3.empty()) {
        cout << que3.top().first << " is poped";
        que3.pop();
        cout << " (size: " <<  que3.size() << ")" << endl;
    }
    cout << endl;
}
