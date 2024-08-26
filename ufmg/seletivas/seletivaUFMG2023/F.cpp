#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()
#define EPS 1e-7

int main(){ _

    int n;
    double R, r;

    cin >> n >> R >> r;
    const long double PI = 3.141592653589793238462643383279502884L;

    if (2 * r <= R) {
        double realy = PI/ asin(r / (R - r));
        cout << (static_cast<int>(realy + EPS) >= n ? "YES" : "NO");
    }
    else cout << (r <= R && n == 1 ? "YES" : "NO");

    return 0;
}
