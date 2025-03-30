#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _ 

    int n, q; cin >> n >> q;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;
    
    vector<vector<pair<int, int>>> queries(n + 1); // [R] => {index, X}  
    for(int i = 0; i < q; i ++){
        int r, x; cin >> r >> x;
        queries[r].push_back({i , x});
    }

    vector<ll> dp(n + 1, LINF);
    vector<int> res(q);
    dp[0] = 0;


    for(int i = 0; i < n; i ++){
        auto it = lower_bound(dp.begin(), dp.end(), arr[i])-dp.begin();
        dp[it] = arr[i];

        // for(int j = 0; j <= min(i + 1, sz(dp)-1) ; j ++) cout << dp[j] << " ";
        // cout << endl;

        for(auto [idx, x] : queries[i + 1]){
            auto el = upper_bound(dp.begin(), dp.end(), x);
            res[idx] = el - dp.begin() -1;
        }
    }

    for(auto el : res) cout << el << endl;
    return 0;
} 
