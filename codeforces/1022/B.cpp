#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, x;
    cin >> n >> x;
    if(n == 1 and x == 0){
        cout << -1 << endl;
        return;
    }

    int b = __builtin_popcount(x);
    if(b >= n) { cout << x << endl; return; }


    if((n-b)%2==0) cout << x+n-b << endl;
    else {
        if(x <= 1) cout << n + 3 << endl;
        else cout << x+n-b+1 << endl;
    }
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
