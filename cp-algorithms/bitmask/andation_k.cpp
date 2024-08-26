#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){
    ll n; cin >> n;
    ll k = n - 1;
    while(n & k != 0){
        n = n & k; k --;
    }
    cout << k << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();

    return 0;
} 
