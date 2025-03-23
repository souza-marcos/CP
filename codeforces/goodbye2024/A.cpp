#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;
    bool ok = false;
    auto calc = [&](){
        for(int i = 0; i < n - 1; i ++){
            if(2 * arr[i] > arr[i+1] and 2 * arr[i + 1] > arr[i]) {
                
                // cout << "EDGE => " <<  arr[i] << " " << arr[i + 1] << endl;
                ok = true;
                break;
            }
        }
    };
    calc();
    if(!ok) reverse(arr.begin(), arr.end()), calc();

    cout << (ok ? "YES": "NO") << endl;
}


int main(){ _
    int t; cin >> t;
    while (t --) solve();
    return 0;
} 
