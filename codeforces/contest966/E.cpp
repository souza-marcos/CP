#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int calc(int i, int j, int n, int m, int k) {
    int vert = max(0, min(i, n - k) - max(i - k + 1, 0) + 1);
    int hor = max(0, min(j, m - k) - max(j - k + 1, 0) + 1);
    return vert * hor;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<ll> heights(w);

    for (int i = 0; i < w; i++) {
        cin >> heights[i];
    }

    vector<int> cont;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur_cell = calc(i, j, n, m, k);
            cont.push_back(cur_cell);
        }
    }
    sort(cont.rbegin(), cont.rend());
    sort(heights.rbegin(), heights.rend());

    ll ans = 0;
    for (int i = 0; i < w; i++) ans += heights[i] * cont[i];
    
    cout << ans << endl;
}


int main() {_
    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}
