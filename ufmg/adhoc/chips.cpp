#include <bits/stdc++.h>
using namespace std;
    
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
    
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
    
void solve(){
    // Find the minimum k such that (k + 1) ^ 2 >= n
    
    ll n;
    cin >> n;

    ll l = -1, r = 1e9 + 1, mid;
    while(l < r){
        mid = (l + r)/2;
        if(mid * mid < n) l = mid + 1;
        else r = mid;
    }

    cout << l - 1 << endl;
}

int main(){ _
    
    int t; cin >> t;
    
    while(t--) solve();
    
    return 0;
} 