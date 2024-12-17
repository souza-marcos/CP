#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(int& el: arr) cin >> el;

    for(int i = 0; i < n; i ++){
        bool ok = true;
        for(int j = 0; j < n; j ++){
            if(i == j) continue;
            int val =  abs(arr[i] - arr[j])%k;
            if(val == 0) { ok = false; break; }
        }
        if(ok) { cout << "YES\n" << i + 1 << endl; return; }
    }
    cout << "NO\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
