#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> arr(n); for(auto&el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    vector<int> order = {2, 2, 3};

    int maxs = 0;
    do {

        ll cur = x, val = 0;
        int i = 0;
        for(; i < n; i ++){
            // cout << i << " " << cur << endl;
            while(cur <= arr[i] and val <= 2){
                cur *= order[val], val ++;
            }
            if(cur <= arr[i]) {
                break;
            }
            cur += arr[i]/2;
            // cout << i << " " << cur << endl;
        }
        maxs = max(maxs, i);

    } while(next_permutation(order.begin(), order.end()));

    cout << maxs << endl;
}   



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
