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


void z_algorithm(const string s, lli *z) {
    lli len = s.length();

    // 0文字目に何を入れたいかに依る
    z[0] = 0;

    lli left = 0;
    lli right = 0;
    REP(i, 1, len) {
        if (i > right) {
            left = right = i;
            while (true) {
                if (right >= len || s[right-left] != s[right])
                    break;
                right++;
            }
            // right: 3 で break;
            z[i] = right - left;
            right--;
        }
        else {
            lli j = i - left;
            if (z[j] < right - i + 1) {
                z[i] = z[j];
            }
            else {
                left = i;
                while (true) {
                    if (right >= len || s[right-left] != s[right])
                        break;
                    right++;
                }
                z[i] = right - left;
                right--;
            }

        }

    }
}

int main() {
    // 最長共通接頭辞の長さをO(N)で求める
    string s1 = "aaabaaaab";
    lli z1[s1.length()];
    z_algorithm(s1, z1);
    cout1(s1);
    ncout1(s1.length(), z1);
    cout << endl;

    string s2 = "ababa";
    lli z2[s2.length()];
    z_algorithm(s2, z2);
    cout1(s2);
    ncout1(s2.length(), z2);
    cout << endl;

    // ある文字列がどこに含まれているかを調べることもできる
    string x = "kata";
    string y = "tanakataro";
    lli len = x.length() + y.length() + 1;
    lli z[len];
    z_algorithm(x + "#" + y, z);
    cout1(x);
    cout1(y);
    //ncout1(len, z);
    REP(i,0,len) {
        if (z[i] == x.length()) {
            cout << "kata first index is " << i - (x.length()+1) << endl;
        }
    }
}

// s1: aaabaaaab
// 0,2,1,0,3,4,2,1,0,
// s2: ababa
// 0,0,3,0,1,
