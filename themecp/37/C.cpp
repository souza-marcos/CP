// https://codeforces.com/problemset/problem/2137/E
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin  >> arr[i];

    auto doOp = [&](){
        vector<int> cnt(n+1);
        for(int i = 0; i < n; i ++) if(arr[i] <= n) cnt[arr[i]] ++;
        int mex = 0;
        for(int i = 0; i <= n; i ++){
            if(cnt[i]) mex ++;
            else break;
        }

        for(int i = 0; i < n; i ++){
            if(arr[i] > mex) arr[i] = mex;
            else {
                if(cnt[arr[i]] == 1) arr[i] = arr[i];
                else arr[i] = mex;
            }
        }
    };

    for(int i = 0; i < min(k, 5ll); i ++){
        doOp();
    }
    k -= min(k, 5ll);

    if(k%2==1) doOp();

    ll res = accumulate(arr.begin(), arr.end(), 0ll);
    cout << res << endl;
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t--) solve();
} 
