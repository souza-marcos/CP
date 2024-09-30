#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, el; cin >> n;
    int maxv = -INF;
    for(int i = 0; i < n; i ++){
        cin >> el;
        maxv = max(maxv, el);
    }
    ll res = maxv;
    maxv = -INF;
    for(int i = 0; i < n; i ++){
        cin >> el;
        maxv = max(maxv, el);
    }
    cout << res + maxv << endl;
    return 0;
} 
