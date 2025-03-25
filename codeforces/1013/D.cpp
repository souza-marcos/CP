#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    ll n, m, k; cin >> n >> m >> k;


    auto check = [&](ll benchsize) -> bool{
        // cada linha
        ll q = m/(benchsize + 1);
        ll qtd = (q * benchsize) + (m%(benchsize+1));
        ll total = n * qtd;
        if(total >= k) return true;
        return false;
    };

    ll l = 0, r = m;
    while(l + 1 < r){
        ll mid = (l + r)/2;
        if(check(mid))r=mid;
        else l = mid;
    }   
    cout << r << endl;



}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
