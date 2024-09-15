#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    ll x, y, z, v; cin >> x >> y >> z >> v;


    ll max_pos = 0;
    for(int i = 1; i <= x; i ++){
        for(int j = 1; j <= y; j++){
            ll k = v / (i * j);
            if(k * i * j != v) continue;
            ll pos = (x - i + 1) * (y - j + 1) * (z - k + 1);
            max_pos = max(max_pos, pos);
        }
    }

    cout << max_pos << endl;

}

int main(){

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
