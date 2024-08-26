#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while(t--){
        ll x, y, a, b; cin >> x >> y >> a >> b;
        b = min(b, 2*a);
        ll val = min(x, y) * b;
        y = max(x, y) - min(x,y);
        val += y * a;
        cout << val << endl;
    }
    return 0;
} 
