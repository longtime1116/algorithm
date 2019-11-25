#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;



#define mod (1000000007)
lli comb_table[2001][2001];


void cal() {
    for (int i = 0; i < 2001; i++)
        comb_table[i][0] = 1;

    for (int j = 0; j < 2001; j++)
        comb_table[j][j] = 1;


    for (int i = 2; i < 2001; ++i) {
        for (int j = 1; j < 2001 and j < i; ++j) {
            comb_table[i][j] = ( comb_table[ i-1 ][j] + comb_table[ i-1 ][ j-1 ] ) % mod;
        }
    }
    return;
}

int main() {
    cal();
    cout << "4C1: " << comb_table[4][1] << endl;
    cout << "4C2: " << comb_table[4][2] << endl;
    cout << "8C3: " << comb_table[8][3] << endl;
    cout << "200C100: " << comb_table[200][100] << endl;
}
