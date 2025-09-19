#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){  _
    ll a, b, x1, y1, x2, y2; 
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    a *= 2, b *= 2;

    ll x1new = (x1 + y1) + 1e10;
    ll x2new = (x2 + y2) + 1e10;
    ll y1new = (x1 - y1) + 1e10;
    ll y2new = (x2 - y2) + 1e10;

    x1new = x1new/a;
    x2new = x2new/a;
    y1new = y1new/b;
    y2new = y2new/b;

    cout << max(abs(x1new - x2new), abs(y1new - y2new)) << endl;
} 