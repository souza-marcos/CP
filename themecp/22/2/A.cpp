#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    
    int n, m; cin >> n >> m;
    vector<pair<int, vector<int>>> arr(n, make_pair(0, vector<int>(m)));

    for(auto& [fr, snd] : arr){
        for(auto& el : snd) cin >> el, fr += el; 
    }
    sort(arr.rbegin(), arr.rend());

    ll res = 0, ps = 0;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            ps += arr[i].second[j];
            res += ps; 
        }
    }
    cout << res << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
