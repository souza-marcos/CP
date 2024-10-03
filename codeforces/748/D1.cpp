#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    int minv = INF;
    vector<int> arr(n); 
    for(int& el: arr) cin >> el, minv = min(minv, el);
    
    set<ll> diff;
    for(int el: arr)
        diff.insert(1LL* el - minv);
    
    vector<ll> v;
    for(auto el: diff){
        if(el == 0) continue;
        v.push_back(el);
    }

    if(sz(diff) == 1) {
        cout << -1 << endl;
        return;
    }

    ll maxv = v[0];
    for(int el: diff){
        maxv = gcd(maxv, el);
    } 
    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
