#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int h, w;
    ll k;
    cin >> h >> w >> k;
    pair<int, int> init;
    cin >> init.first >> init.second;

    int v[h][w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }

    int t = min((ll)k, (ll)w * h);
    vector<vector<vector<ll>>> ma(h, vector<vector<ll>>(w, vector<ll>(t + 1, -1)));

    auto val = [&](int i, int j){
        return (i >= 0 && j >= 0 && i < h && j < w);
    };

    vector<pair<int, int>> mvs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    ma[init.first - 1][init.second - 1][0] = v[init.first - 1][init.second - 1];

    // Filling the DP table
    for(int now = 0; now < t; now++) {
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(ma[i][j][now] < 0) continue;
                for(auto [di, dj] : mvs) {
                    int newi = i + di, newj = j + dj;
                    if(val(newi, newj)) {
                        ma[newi][newj][now + 1] = max(ma[newi][newj][now + 1], ma[i][j][now] + v[newi][newj]);
                    }
                }
            }
        }
    }

    ll val_max = 0;
    ll rest = k - t;

    // Finding the maximum value
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(ma[i][j][t] < 0) continue;
            val_max = max(val_max, ma[i][j][t] + rest * v[i][j]);
        }
    }

    cout << val_max << endl;
    return 0;
}
