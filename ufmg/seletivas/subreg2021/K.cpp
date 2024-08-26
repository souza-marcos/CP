#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int t, D, m; cin >> t >> D >> m;
    int last = 0, cur, maxv = 0;
    while(m --){
        cin >> cur;
        maxv = max(cur - last, maxv);
        last = cur;
    }
    maxv = max(D - last, maxv);
    cout << (maxv >= t? "Y":"N") << endl;
    return 0;
} 
