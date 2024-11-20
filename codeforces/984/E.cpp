#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> arr(k, vector<int>(n));
    vector<vector<int>> pref(k, vector<int>(n+1));


    for(int i = 0; i < n; i ++){
        for(int j = 0; j < k; j++){
            cin >> arr[j][i];
            pref[j][i+1] = pref[j][i] | arr[j][i];
        }
    }

    // for(int i = 0; i <= n; i ++){
    //     for(int j = 0; j < k; j++){
    //         cout << pref[i][j] << " ";
    //     }cout << endl;
    // }

    // b search
    for(int i = 0; i < q; i ++){
        // cout << i << " query: " << endl;
        
        int tt; cin >> tt;
        int l = 1, r = n + 1;
        while(tt --){
            int region, v; char s; cin>> region >> s >> v;
            region --;

            if(s == '>'){
                l = max(l, (int)(upper_bound(pref[region].begin(), pref[region].end(), v) - pref[region].begin()));
            }
            else { // <
                r = min(r, (int)(lower_bound(pref[region].begin(), pref[region].end(), v) - pref[region].begin()));
            }

        }
        if(l >= r) cout << -1 << endl;
        else cout << l << endl;
    }
}

int main(){ //_
    solve();
    return 0;
} 
