#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    ll n, m, a, b; cin >> n >> m >> a >> b;
    
    auto get_cuts = [&](ll side) -> int {
        int res = 0;
        while(side > 1){
            res ++;
            side = ceil(side/2.0);
        }
        return res;
    };
    int minv = INF;
    minv = min(minv, 1 + get_cuts(a) + get_cuts(m));
    minv = min(minv, 1 + get_cuts(n-a+1) + get_cuts(m));
    minv = min(minv, 1 + get_cuts(n) + get_cuts(b));
    minv = min(minv, 1 + get_cuts(n) + get_cuts(m-b+1));

    cout << minv << endl;
}

int main(){_  
    int t; cin >> t;
    while(t--) solve();
} 
