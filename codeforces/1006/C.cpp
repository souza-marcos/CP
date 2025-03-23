#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n, x; cin >> n >> x;
    

    for(int i = 0; i<n-1; i++){
        cout << i << " ";
        x = x & (~i);
    }
    cout << (x > 0 ? x: n-1) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
