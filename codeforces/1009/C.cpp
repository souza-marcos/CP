#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    
    int x; cin >> x;
    int res = 0;
    bool found = false, one = false, zero = false;
    for(int i = 31; i >= 0; i --){
        if(found){
            int d = (x >> i) & 1;
            res |= (1 << i);
            if(d) one = true;
            else zero = true;
        }
        if(!found and (x >> i) & 1){
            found = true;
        }
    }
    if(one and zero){
        cout << res << endl;
    } else cout << -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
