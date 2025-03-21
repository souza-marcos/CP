#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    if(n == 1 and m == 0 and k >= 2){
        cout << "YES\n";
        return;
    }

    if(m > n * (n - 1)/ 2 or m < n-1){
        cout << "NO\n";
        return;
    }

    if(k == 3 and m < n * (n - 1)/2){
        cout << "NO\n";
        return;
    }   

    if(k < 3) cout << "NO\n";
    else cout << "YES\n";


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
