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
    vector<int> arr(n); for(auto& el: arr) cin >> el;

    bool ok = true;
    for(int i = 1; i < n-1; i ++){
        int a = arr[i-1];
        if(arr[i] < 2 * a or arr[i + 1] < a) {
            ok = false;
            break;
        }
        arr[i-1] = 0, arr[i] -= 2 * a, arr[i + 1] -= a;
    }
    for(auto el: arr) if(el != 0) ok = false;
 
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
