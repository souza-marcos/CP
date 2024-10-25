#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, i = 0; cin >> n;

    vector<pair<ll, int>> arr(n); 
    for(auto& [el, in]: arr) cin >> el, in = i, i ++;
    
    sort(arr.begin(), arr.end());
    ll fr = 1;
    for(int i = 1; i < n; i ++){
        fr += arr[i].first - arr[0].first + 1;
    }
    
    vector<ll> res(n); res[arr[0].second] = fr;
    int before = 0, after = n-2;
    for(int i = 1; i < n; i ++){
        ll diff = arr[i].first - arr[i-1].first;

        // cout << "Diff: " << diff << endl;
        ll cur = fr + (before - after) * diff;
        // cout << "before -after: " << before - after << endl;
        // cout << "cur: " << cur << endl; 
        // cout << "I: " << arr[i].second << endl << endl;
        fr = cur;
        res[arr[i].second] = cur;
        before ++, after --;
    }

    for(auto el: res) cout << el << " ";
    cout << endl;    
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
