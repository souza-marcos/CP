#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    // Find i, j, k that a_i + a_j + a_k is maximized
    int n; cin >> n;
    vector<pair<int, int>> arr(n); 
    vector<pair<int, int>> res[3];
    for(int j = 0; j < 3; j ++){
        int k = 0; 
        for(auto& [fr, sn]: arr) cin >> fr, sn = k ++;

        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < min(5,sz(arr)); i++)
            res[j].push_back(arr[i]);
    }

    int maxv = -INF;
    for(int i = 0; i < sz(res[0]); i ++){
        for(int j = 0; j < sz(res[0]); j ++){
            if(res[0][i].second == res[1][j].second) continue;
            for(int k = 0; k < sz(res[0]); k ++){
                if(res[1][j].second == res[2][k].second 
                or res[0][i].second == res[2][k].second) continue;
                // cout << i << j << k << " " << res[0][i].second << " " << res[1][j].second << " " << res[2][k].second << " " << endl; 
                maxv = max(maxv, res[0][i].first + res[1][j].first + res[2][k].first);
            } 
        }
    }
    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
