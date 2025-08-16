#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    int n, k; cin >> n >> k; k--;
    string s; cin >> s;
    if(k == 0 or k == n-1) {
        cout << 1 << endl;
        return;    
    }

    int left = k, right = k;
    while(left >= 0 and s[left]=='.') left --;
    while(right < n and s[right]=='.') right++;
    right = n - right;
    left ++;
    // cout << left << " " << right << endl;
    // cout << left << " " << n-1-k << " " << right  << " " << k << endl;
    cout << max(min(left, n-1-k), min(right, k)) + 1 << endl; 

    // cout << min(, ) << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
