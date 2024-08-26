#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _

    int h, w, k; cin >> h >> w >> k;
    pair<int, int> init;
    cin >> init.first >> init.second;
    int t = min((ll)k, (ll)w * h);
    int v[h][w];
    ll ma[h][w][t + 1];

    memset(ma, -1, sizeof ma);

    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            cin >> v[i][j];
        }
    }

    auto val = [&](int i, int j){
        return (i >= 0 and j >= 0 and i < h and j < w);
    };

    vector<pair<int, int>> mvs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    ma[init.first -1][init.second -1][0] = 0;
    // Until fill 
    for(int now = 0; now < t; now ++){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(ma[i][j][now] < 0) continue;

                for(auto[ newi, newj] : mvs){
                    newi += i, newj += j;
                    if(val(newi, newj) and ma[i][j][now] + v[newi][newj] > ma[newi][newj][now + 1]){
                        ma[newi][newj][now+1] = ma[i][j][now] + v[newi][newj];
                    }
                }
            }
        }
    }

    ll val_max = 0;
    ll rest = k - t;
    // cout << rest << endl;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(ma[i][j][t] < 0) continue;
            // cout << ma[i][j][t] << " ";
            val_max = max(val_max, ma[i][j][t] + rest * v[i][j]); 
        }
        // cout << endl;
    }
    cout << val_max << endl;
    return 0;
} 
