#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
#define f first
#define s second

int main(){ _
    string ab, ac, bc; cin >> ab >> ac >> bc;

    vector<pair<int, char>> a(3); a[0].f = a[1].f = a[2].f = 0;
    a[0].s = 'A', a[1].s = 'B', a[2].s = 'C';
 
    if(ab == ">") a[0].f ++;
    else a[1].f ++;

    if(ac == ">") a[0].f ++;
    else a[2].f ++;

    if(bc == ">") a[1].f ++;
    else a[2].f ++;

    sort(a.begin(), a.end());

    cout << a[1].s << endl;
    return 0;
} 
