#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

bool ckmax(int& a, int b){
    if(a >= b) return false;
    a = b;
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n); for(int& el: arr) cin >> el;

    bool ok = true;
    for(int i = 0; i < n-1; i ++){
        if(arr[i] > arr[i + 1]) {
            ok = false;
            break;
        }
        arr[i + 1] -= arr[i];
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
