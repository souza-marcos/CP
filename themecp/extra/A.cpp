#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n; cin >> n;

    auto has7 = [&](ll val){
        string s = to_string(val);
        for(auto el : s) if(el == '7') return true;
        return false;
    };

    auto md = [&](ll x) -> int{
        for(ll i = 0; i <= 9; i ++)
            if(has7(n + x*i)) return i;
        return 9;
    };

    int minv = INF;
    for (ll i = 0; i < n*10; i = i*10 + 9){
        minv = min(minv, md(i));
    }

    cout << minv << endl;
}



int main(){// _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
