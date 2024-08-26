#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl "\n"
#define sz(x) (int)x.size()

int main(){ _
    ll k, n, w;
    cin >> k >> n >> w;
    w = (w + 1)* w/2;
    w = w * k;
    ll res = w - n;
    if(res < 0) cout << 0 << endl;
    else cout << res << endl;
    return 0;
} 
