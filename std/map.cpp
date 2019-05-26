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
    // 重複を許す場合は multimap
    map<string, int> m;

    cout << "----- insert -----" << endl;
    m.insert(make_pair("abc", 20));
    m.insert(make_pair("bcd", 10));
    m.insert(make_pair("azz", 30));

    REPIT(it, m) {
        printf("key: %s, value: %d\n", it->first.c_str(), it->second);
    }

    cout << "----- erase -----" << endl;
    m.erase("bcd");
    REPIT(it, m) {
        printf("key: %s, value: %d\n", it->first.c_str(), it->second);
    }
}
