#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _
    int n; cin >> n;
    vector<ll> arr(n), pref(n+1); 

    int i = 0;
    for(ll & el : arr) cin >> el, pref[i + 1] = pref[i] + el, i ++;

    ll memo[n][n];
    for(int i = 0; i < n; i ++) memo[i][i] = 0;

    for(int s = 2; s <= n; s ++){
        for(int l = 0, r = l + s - 1; r < n; l ++, r ++){
            memo[l][r] = LINF; 
            for(int t = l; t < r; t ++){
                memo[l][r] = min(memo[l][r], memo[l][t] + memo[t + 1][r] + (pref[r + 1] - pref[l]));
            }
        }
    }
    cout << memo[0][n-1] << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < n; j ++){
    //         cout << memo[i][j] << " ";
    //     }cout << endl;
    // }
    return 0;
} 
