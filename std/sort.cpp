#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
typedef vector<lli> vlli;


// 小さい順、大きい順にソート
class LessGreaterCompare
{
public:
    bool operator()(P n1, P n2) {
        if (n1.first < n2.first) {
            return true;
        }
        else if (n1.first == n2.first) {
            return n1.second > n2.second;
        }
        return false;
    }
};

// 大きい順、小さい順にソート
class GreaterLessCompare
{
public:
    bool operator()(P n1, P n2) {
        if (n1.first > n2.first) {
            return true;
        }
        else if (n1.first == n2.first) {
            return n1.second < n2.second;
        }
        return false;
    }
};

// secondだけ見て小さい順
class OnlySecondLessCompare
{
public:
    bool operator()(P n1, P n2) {
        return n1.second<=n2.second;
    }
};

// secondだけ見て大きい順
class OnlySecondGreaterCompare
{
public:
    bool operator()(P n1, P n2) {
        return n1.second>=n2.second;
    }
};

int main() {
    lli n;

    cout << "# array" << endl;
    lli ary[] = {1,3,5,2,4};
    n = ARRAY_LENGTH(ary);

    cout << "小さい順" << endl;
    sort(ary, ary+n); // 1,2,3,4,5
    REP(i,0,n) {cout<<ary[i];} cout << endl;

    cout << "大きい順" << endl;
    sort_r(ary, ary+n); // 5,4,3,2,1
    REP(i,0,n) {cout<<ary[i];} cout << endl;




    cout << endl;
    cout << "# vector" << endl;
    vlli vec = {1,3,5,2,4};
    n = vec.size();

    cout << "小さい順" << endl;
    sort(vec.begin(), vec.end()); // 1,2,3,4,5
    REP(i,0,n) {cout<<vec[i];} cout << endl;

    cout << "大きい順" << endl;
    sort_r(vec.begin(), vec.end()); // 5,4,3,2,1
    REP(i,0,n) {cout<<vec[i];} cout << endl;




    cout << endl;
    cout << "# pair" << endl;
    vector<P> p;
    p.push_back(P(1,6));
    p.push_back(P(1,5));
    p.push_back(P(1,3));
    p.push_back(P(1,4));
    p.push_back(P(1,1));
    p.push_back(P(2,1));
    p.push_back(P(2,1));
    p.push_back(P(2,2));
    p.push_back(P(2,5));
    n = p.size();

    cout << "first で小さい順、同じ場合は second で小さい順" << endl;
    sort(p.begin(), p.end());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;

    cout << "first で大きい順、同じ場合は second で大きい順" << endl;
    sort(p.begin(), p.end(), greater<P>());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;

    cout << "first で小さい順、同じ場合は second で大きい順" << endl;
    sort(p.begin(), p.end(), LessGreaterCompare());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;

    cout << "first で大きい順、同じ場合は second で小さい順" << endl;
    sort(p.begin(), p.end(), GreaterLessCompare());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;

    cout << "second で小さい順" << endl;
    sort(p.begin(), p.end(), OnlySecondLessCompare());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;

    cout << "second で大きい順" << endl;
    sort(p.begin(), p.end(), OnlySecondGreaterCompare());
    REP(i,0,n) {coutp(p[i]);} cout<<endl;








    cout << "# priority queue" << endl;
    cout << "## lli" << endl;
    cout << "大きい順にpop" << endl;
    priority_queue<lli> pque;
    pque.push(0); pque.push(2); pque.push(3); pque.push(5); pque.push(-1);
    while (!pque.empty()) {cout << pque.top() << ", "; pque.pop();} cout << endl;

    cout << "小さい順にpop" << endl;
    priority_queue< lli, vector<lli>, greater<lli> > pque_greater;
    pque_greater.push(0); pque_greater.push(2); pque_greater.push(3); pque_greater.push(5); pque_greater.push(-1);
    while (!pque_greater.empty()) {cout << pque_greater.top() << ", "; pque_greater.pop();} cout << endl;

    cout << "## pair" << endl;
    // 大きい順にpop
    priority_queue<P> pque_pair;
    pque_pair.push(P(1,6)); pque_pair.push(P(1,5)); pque_pair.push(P(1,3));
    pque_pair.push(P(1,4)); pque_pair.push(P(1,1)); pque_pair.push(P(2,1));
    pque_pair.push(P(2,1)); pque_pair.push(P(2,2)); pque_pair.push(P(2,5));
    while (!pque_pair.empty()) {coutp(pque_pair.top()); pque_pair.pop();} cout << endl;

    // 小さい順にpop
    priority_queue<P, vector<P>, greater<P>> pque_pair_greater;
    pque_pair_greater.push(P(1,6)); pque_pair_greater.push(P(1,5)); pque_pair_greater.push(P(1,3));
    pque_pair_greater.push(P(1,4)); pque_pair_greater.push(P(1,1)); pque_pair_greater.push(P(2,1));
    pque_pair_greater.push(P(2,1)); pque_pair_greater.push(P(2,2)); pque_pair_greater.push(P(2,5));
    while (!pque_pair_greater.empty()) {coutp(pque_pair_greater.top()); pque_pair_greater.pop();} cout << endl;

    // 二つ目だけみて大きい順にpop
    priority_queue< P, vector<P>, OnlySecondLessCompare > pque_pair_second_less;
    pque_pair_second_less.push(P(1,6)); pque_pair_second_less.push(P(1,5)); pque_pair_second_less.push(P(1,3));
    pque_pair_second_less.push(P(1,4)); pque_pair_second_less.push(P(1,1)); pque_pair_second_less.push(P(2,1));
    pque_pair_second_less.push(P(2,1)); pque_pair_second_less.push(P(2,2)); pque_pair_second_less.push(P(2,5));
    while (!pque_pair_second_less.empty()) {coutp(pque_pair_second_less.top()); pque_pair_second_less.pop();} cout << endl;

    // 二つ目だけみて小さい順にpop
    priority_queue< P, vector<P>, OnlySecondGreaterCompare > pque_pair_second_greater;
    pque_pair_second_greater.push(P(1,6)); pque_pair_second_greater.push(P(1,5)); pque_pair_second_greater.push(P(1,3));
    pque_pair_second_greater.push(P(1,4)); pque_pair_second_greater.push(P(1,1)); pque_pair_second_greater.push(P(2,1));
    pque_pair_second_greater.push(P(2,1)); pque_pair_second_greater.push(P(2,2)); pque_pair_second_greater.push(P(2,5));
    while (!pque_pair_second_greater.empty()) {coutp(pque_pair_second_greater.top()); pque_pair_second_greater.pop();} cout << endl;

}
