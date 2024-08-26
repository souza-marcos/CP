#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;
    ll sum = 0, minabs = INF;
    for(int i = 0; i < n; i ++){
        sum += abs(a[i] - b[i]);
        minabs = min(minabs, (ll)abs(a[i] - b[n]));
        minabs = min(minabs, (ll)abs(b[i] - b[n]));
        
        int c = min(a[i], b[i]), d = max(a[i], b[i]);
        if(b[n] >= c and b[n] <= d) minabs = 0;
    }

    cout << sum + minabs + 1 << endl;
}

int main(){ _
    
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
